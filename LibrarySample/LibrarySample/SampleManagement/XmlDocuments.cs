﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using Windows.Media.Core;

namespace LibrarySample.SampleManagement
{
    public static class XmlDocuments
    {
        private static bool _isLoaded = false;

        private static void LoadLibrary(string directoryPath, Dictionary<string, XElement> libraryDocuments)
        {
            foreach (string filePath in Directory.GetFiles(directoryPath))
            {
                libraryDocuments.Add(filePath, XElement.Load(filePath));
            }
        }

        public static bool LoadDocuments()
        {
            if (_isLoaded) return false;
            _isLoaded = true;

            LoadLibrary(XmlPath.CLibraryDirectory, _cLibraryDocuments);
            LoadLibrary(XmlPath.CppLibraryDirectory, _cppLibraryDocuments);
            LoadLibrary(XmlPath.Win32LibraryDirectory, _win32LibraryDocuments);
            LoadLibrary(XmlPath.CppWinRTNamespaceLibraryDirectory, _cppWinRTNamespaceLibraryDocuments);
            LoadLibrary(XmlPath.UwpLibraryDirectory, _uwpLibraryDocuments);
            LoadLibrary(XmlPath.DotNetLibraryDirectory, _dotNetLibraryDocuments);

            return true;
        }

        public static async Task<bool> LoadDocumentsAsync()
        {
            return await Task.Run(LoadDocuments);
        }

        public static IReadOnlyDictionary<string, XElement> GetDocuments(Library libraryType)
        {
            return libraryType switch
            {
                Library.C => CLibraryDocuments,
                Library.Cpp => CppLibraryDocuments,
                Library.Win32 => Win32LibraryDocuments,
                Library.CppWinRTNamespace => CppWinRTNamespaceLibraryDocuments,
                Library.Uwp => UwpLibraryDocuments,
                Library.DotNet => DotNetLibraryDocuments,
                _ => throw new NotImplementedException()
            };
        }

        private static readonly Dictionary<string, XElement> _cLibraryDocuments = [];
        public static IReadOnlyDictionary<string, XElement> CLibraryDocuments => _cLibraryDocuments;

        private static readonly Dictionary<string, XElement> _cppLibraryDocuments = [];
        public static IReadOnlyDictionary<string, XElement> CppLibraryDocuments => _cppLibraryDocuments;

        private static readonly Dictionary<string, XElement> _win32LibraryDocuments = [];
        public static IReadOnlyDictionary<string, XElement> Win32LibraryDocuments => _win32LibraryDocuments;

        private static readonly Dictionary<string, XElement> _cppWinRTNamespaceLibraryDocuments = [];
        public static IReadOnlyDictionary<string, XElement> CppWinRTNamespaceLibraryDocuments => _cppWinRTNamespaceLibraryDocuments;

        private static readonly Dictionary<string, XElement> _uwpLibraryDocuments = [];
        public static IReadOnlyDictionary<string, XElement> UwpLibraryDocuments => _uwpLibraryDocuments;

        private static readonly Dictionary<string, XElement> _dotNetLibraryDocuments = [];
        public static IReadOnlyDictionary<string, XElement> DotNetLibraryDocuments => _dotNetLibraryDocuments;
    }
}
