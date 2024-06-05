namespace CSharpConsoleSample
{
    internal class Program
    {
        private static bool _isConsole;
        internal static bool IsConsole => _isConsole;

        //args[0] フォルダー
        //args[1] 関数名
        //args[2] true: コンソール, false: アプリ内パイプ
        static void Main(string[] args)
        {
            if (args.Length != 3) Environment.Exit(1);

            _isConsole = bool.Parse(args[2]);

            SampleRunner.Run(args[0], args[1]);
        }
    }
}
