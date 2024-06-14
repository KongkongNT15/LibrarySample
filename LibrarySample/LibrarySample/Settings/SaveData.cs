using LibrarySample.Languages;
using LibrarySample.SampleManagement;
using Microsoft.UI.Xaml;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibrarySample.Settings
{
    public class SaveData
    {
        private CVersion _cVersion = CVersion.C17;
        public static CVersion CVersion
        {
            get => Instance._cVersion;
            set => Instance._cVersion = value;
        }

        private ProcesserType _cProcesserType = ProcesserType.X64;
        public static ProcesserType CProcesserType
        {
            get => Instance._cProcesserType;
            set => Instance._cProcesserType = value;
        }

        private CppVersion _cppVersion = CppVersion.Cpp17;
        public static CppVersion CppVersion
        {
            get => Instance._cppVersion;
            set => Instance._cppVersion = value;
        }

        private ProcesserType _cppProcesserType = ProcesserType.X64;
        public static ProcesserType CppProcesserType
        {
            get => Instance._cppProcesserType;
            set => Instance._cppProcesserType = value;
        }

        private ProcesserType _win32ProcesserType = ProcesserType.X64;
        public static ProcesserType Win32ProcesserType
        {
            get => Instance._win32ProcesserType;
            set => Instance._win32ProcesserType= value;
        }

        private CodeLanguage _win32CodeLanguage = CodeLanguage.CWin32;
        public static CodeLanguage Win32CodeLanguage
        {
            get => Instance._win32CodeLanguage;
            set => Instance._win32CodeLanguage = value;
        }

        private ProcesserType _cppWinRTNamespaceProcesserType = ProcesserType.X64;
        public static ProcesserType CppWinRTNamespaceProcesserType
        {
            get => Instance._cppWinRTNamespaceProcesserType;
            set => Instance._cppWinRTNamespaceProcesserType= value;
        }

        private CodeLanguage _uwpCodeLanguage = CodeLanguage.CSharp;
        public static CodeLanguage UwpCodeLanguage
        {
            get => Instance._uwpCodeLanguage;
            set => Instance._uwpCodeLanguage = value;
        }

        private WinRTDesign _uwpCodeDesign = WinRTDesign.XAML;
        public static WinRTDesign UwpCodeDesign
        {
            get => Instance._uwpCodeDesign;
            set => Instance._uwpCodeDesign = value;
        }

        private ProcesserType _uwpProcesserType = ProcesserType.X64;
        public static ProcesserType UwpProcesserType
        {
            get => Instance._uwpProcesserType;
            set => Instance._uwpProcesserType = value;
        }

        private uint _waitTime = 50;
        public static uint WaitTime
        {
            get => Instance._waitTime;
            set => Instance._waitTime = value;
        }

        private ElementTheme _requestedTheme = ElementTheme.Default;
        public static ElementTheme RequestedTheme
        {
            get => Instance._requestedTheme;
            set
            {
                Instance._requestedTheme = value;
                MainWindow.ChangeAllWindowTheme(value);
                SettingWindow.SetTheme(value);
            }
        }

        private static SaveData Instance { get; } = new SaveData();

        private const string SaveDataPath = "../SaveData.ini";

        public static void Save()
        {
            //StreamWriterを開いている途中にnew SaveData()が実行されないようにする
            _ = Instance;

            using StreamWriter streamWriter = new StreamWriter(SaveDataPath);

            WriteData(streamWriter, "CVersion", CVersion.ToString());
            WriteData(streamWriter, "CProcesserType", CProcesserType.ToString());
            WriteData(streamWriter, "CppVersion", CppVersion.ToString());
            WriteData(streamWriter, "CppProcesserType", CppProcesserType.ToString());
            WriteData(streamWriter, "Win32CodeLanguage", Win32CodeLanguage.ToString());
            WriteData(streamWriter, "Win32ProcesserType", Win32ProcesserType.ToString());
            WriteData(streamWriter, "CppWinRTNamespaceProcesserType", CppWinRTNamespaceProcesserType.ToString());
            WriteData(streamWriter, "UwpCodeLanguage", UwpCodeLanguage.ToString());
            WriteData(streamWriter, "UwpCodeDesign", UwpCodeDesign.ToString());
            WriteData(streamWriter, "UwpProcesserType", UwpProcesserType.ToString());
            WriteData(streamWriter, "WaitTime", WaitTime.ToString());
            WriteData(streamWriter, "RequestedTheme", RequestedTheme.ToString());
        }

        private static void WriteData(StreamWriter streamWriter, string property, string value)
        {
            streamWriter.WriteLine($"{property}:{value}");
        }

        //iniを読み込む
        private SaveData()
        {
            //設定ファイルが見つからなければ何もしない
            if (!File.Exists(SaveDataPath)) return;

            using StreamReader streamReader = new StreamReader(SaveDataPath);

            while (!streamReader.EndOfStream)
            {
                string[] value = streamReader.ReadLine().Split(':');

                switch (value[0])
                {
                    case "CVersion":
                        _cVersion = EnumConverter.ToCLanguage(value[1]);
                        break;

                    case "CProcesserType":
                        _cProcesserType = EnumConverter.ToProcesserType(value[1]);
                        break;

                    case "CppVersion":
                        _cppVersion = EnumConverter.ToCppVersion(value[1]);
                        break;

                    case "CppProcesserType":
                        _cppProcesserType = EnumConverter.ToProcesserType(value[1]);
                        break;

                    case "Win32CodeLanguage":
                        _win32CodeLanguage = EnumConverter.ToCodeLanguage(value[1]);
                        break;

                    case "Win32ProcesserType":
                        _win32ProcesserType = EnumConverter.ToProcesserType(value[1]);
                        break;

                    case "CppWinRTNamespaceProcesserType":
                        _cppWinRTNamespaceProcesserType = EnumConverter.ToProcesserType(value[1]);
                        break;

                    case "UwpCodeLanguage":
                        _uwpCodeLanguage = EnumConverter.ToCodeLanguage(value[1]);
                        break;

                    case "UwpCodeDesign":
                        _uwpCodeDesign = EnumConverter.ToWinRTDesign(value[1]);
                        break;

                    case "UwpProcesserType":
                        _uwpProcesserType = EnumConverter.ToProcesserType(value[1]);
                        break;

                    case "WaitTime":
                        _waitTime = uint.Parse(value[1]);
                        break;

                    case "RequestedTheme":
                        _requestedTheme = EnumConverter.ToElementTheme(value[1]);
                        break;
                        
                }
            }
        }

    }
}
