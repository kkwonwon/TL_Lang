using System.Text;
using Define;

namespace Analysis
{
    enum CharType
    {
        Unknown,
        WhiteSpace,
        NumberLiteral,
        StringLiteral,
        IdentifierAndKeyword,
        OperatorAndPunctuator
    }

    class Scan
    {
        private static string ScanFiles(string[] files)
        {
            StringBuilder fileContent = new();
            try
            {
                foreach (string f in files)
                {
                    using StreamReader sr = new(f);
                    fileContent.Append(sr.ReadToEnd());
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception : " + e.Message);
            }
            return fileContent.ToString();
        }

        public static List<Token> ScanToken(string[] files) 
        {
            string code = ScanFiles(files);
            List<Token> result = [];
            code += '\0';
            Console.WriteLine(code); //debug
            while (false)
            {
                
            }
            result.Add(new(Kind.EndOfCode));
            return result;
        }
    }
}