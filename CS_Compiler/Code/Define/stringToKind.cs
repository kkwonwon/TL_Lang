namespace Define {
    class STK {
        public static readonly Dictionary<string, Kind> stringToKind = new()
        {
            {"#unknown",       Kind.Unknown},
            {"#EndOfCode",     Kind.EndOfCode},

            {"참",             Kind.TrueLiteral},
            {"거짓",           Kind.FalseLiteral},
            {"#Number",        Kind.NumberLiteral},
            {"#String",        Kind.StringLiteral},
            {"#identifier",    Kind.Identifier},

            {"함수",           Kind.Function},
            {"반환한다",       Kind.Return},
            {"만약",           Kind.If},
            {"아니면",         Kind.Else}
        };
    }
}