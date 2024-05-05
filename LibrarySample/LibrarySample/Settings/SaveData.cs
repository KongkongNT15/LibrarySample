using LibrarySample.Languages;
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

        private uint _waitTime = 400;
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
