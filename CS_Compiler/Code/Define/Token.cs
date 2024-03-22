namespace Define
{
    class Token
    {
        Kind kind { get; set; }
        string? str { get; set; }

        public Token()
        {
            kind = Kind.Unknown;
        }

        public Token(Kind kind)
        {
            this.kind = kind;
        }
    }
}