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
        Identifier,
        Keyword,
        OperatorAndPunctuator
    }

    class CharTypeChecker
    {
        public static bool IsWhiteSpace(char c) { return ' ' == c || '\t' == c || '\r' == c || '\n' == c; }
        public static bool IsNumberLiteral(char c) { return '0' <= c && '9' >= c; }
        public static bool IsStringLiteral(char c) { return '\"' != c; }
        public static bool IsIdentifier(char c) { return '\'' != c; }
        public static bool IsKeyword(char c) { return '가' <= c && '힣' >= c; }
    }

    class Scan
    {
        static char[] codeArray = [];
        static int index = 0;

        class ScanChar
        {
            static bool IsCharType(char c, CharType type)
            {
                return type switch
                {
                    CharType.NumberLiteral => CharTypeChecker.IsNumberLiteral(c) || '.' == c,
                    CharType.StringLiteral => CharTypeChecker.IsStringLiteral(c),
                    CharType.Identifier => CharTypeChecker.IsIdentifier(c),
                    CharType.Keyword => CharTypeChecker.IsKeyword(c) || ' ' == c,
                    _ => false,
                };
            }

            public static Token ScanNumberLiteral()
            {
                string s = "";
                while (IsCharType(codeArray[index], CharType.NumberLiteral))
                    s += codeArray[index++];
                return new Token(Kind.NumberLiteral, s);
            }

            public static Token ScanStringLiteral()
            {
                string s = "";
                index++;
                while (IsCharType(codeArray[index], CharType.StringLiteral))
                    s += codeArray[index++];
                if ('\"' != codeArray[index])
                {
                    Console.WriteLine("문자열이 종료되지 않았습니다.");
                    Environment.Exit(1);
                }
                return new Token(Kind.StringLiteral, s);
            }

            public static Token ScanIdentifier()
            {
                string s = "";
                index++;
                while (IsCharType(codeArray[index], CharType.Identifier))
                    s += codeArray[index++];
                if ('\'' != codeArray[index])
                {
                    Console.WriteLine("식별자가 종료되지 않았습니다.");
                    Environment.Exit(1);
                }
                return new Token(Kind.Identifier, s);
            }

            public static Token ScanKeyword()
            {
                string s = "";
                Kind kind = Kind.Unknown;
                while (IsCharType(codeArray[index], CharType.Keyword))
                {
                    s += codeArray[index++];
                    foreach (var stk in STK.stringToKind)
                    {
                        if (stk.Key == s)
                        {
                            kind = stk.Value;
                            break;
                        }
                    }
                }
                return new Token(kind, s);
            }
        }

        private static string ScanFiles(string[] files)
        {
            StringBuilder fileContent = new();
            try
            {
                foreach (string f in files)
                {
                    using StreamReader sr = new(f);
                    fileContent.Append(sr.ReadToEnd() + '\n');
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception : " + e.Message);
            }
            return fileContent.ToString();
        }

        private static CharType GetCharType(char c)
        {
            if (CharTypeChecker.IsWhiteSpace(c))
                return CharType.WhiteSpace;
            if (CharTypeChecker.IsNumberLiteral(c))
                return CharType.NumberLiteral;
            if (CharTypeChecker.IsStringLiteral(c))
                return CharType.StringLiteral;
            if (CharTypeChecker.IsIdentifier(c))
                return CharType.Identifier;
            if (CharTypeChecker.IsKeyword(c))
                return CharType.Keyword;
            return CharType.Unknown;
        }

        public static List<Token> ScanToken(string[] files)
        {
            string code = ScanFiles(files);
            List<Token> result = [];
            code += '\0';
            // Console.WriteLine(code); //debug
            codeArray = code.ToCharArray();
            while (codeArray[index] != '\0')
            {
                // Console.Write(codeArray[index++]); //debug
                switch (GetCharType(codeArray[index]))
                {
                    case CharType.WhiteSpace:
                        index++;
                        break;
                    case CharType.NumberLiteral:
                        result.Add(ScanChar.ScanNumberLiteral());
                        break;
                    case CharType.StringLiteral:
                        result.Add(ScanChar.ScanStringLiteral());
                        break;
                    case CharType.Identifier:
                        result.Add(ScanChar.ScanIdentifier());
                        break;
                    case CharType.Keyword:
                        result.Add(ScanChar.ScanKeyword());
                        break;
                }
            }
            result.Add(new(Kind.EndOfCode));
            return result;
        }
    }
}