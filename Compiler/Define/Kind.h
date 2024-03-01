enum class Kind {
    Unknown, EndOfCode,

    NullLiteral,
    TrueLiteral,FalseLiteral,
    NumberLiteral,StringLiteral,
    Identifier,
    
    Function, Return, 
    For, Break, Continue, 
    If, Else
};