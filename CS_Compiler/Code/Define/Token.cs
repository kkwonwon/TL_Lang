namespace Define
{
    class Token
    {
        private Kind Kind { get; set; }
        private string? Str { get; set; }

        public Token()
        {
            Kind = Kind.Unknown;
        }

        public Token(Kind kind)
        {
            Kind = kind;
        }

        public Token(Kind kind, string str) {
            Kind = kind;
            Str = str;
        }
    }
}