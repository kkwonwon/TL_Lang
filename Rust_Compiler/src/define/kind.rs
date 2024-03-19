use lazy_static::lazy_static;
use std::collections::HashMap;

    pub enum Kind {    
    Unknown, EndOfCode,

    NullLiteral,
    TrueLiteral,FalseLiteral,
    NumberLiteral,StringLiteral,
    Identifier,

    Function, Return, 
    For, Break, Continue, 
    If, Else
}

lazy_static! {
    pub static ref STRING_TO_KIND: HashMap<String, Kind> = {
        let mut map = HashMap::new();
        map.insert("#unknown".to_string(),       Kind::Unknown);
        map.insert("#EndOfCode".to_string(),     Kind::EndOfCode);
        map.insert("참".to_string(),             Kind::TrueLiteral);
        map.insert("거짓".to_string(),           Kind::FalseLiteral);
        map.insert("#Number".to_string(),        Kind::NumberLiteral);
        map.insert("#String".to_string(),        Kind::StringLiteral);
        map.insert("#identifier".to_string(),    Kind::Identifier);
        map.insert("함수".to_string(),           Kind::Function);
        map.insert("반환한다".to_string(),       Kind::Return);
        map.insert("만약".to_string(),           Kind::If);
        map.insert("아니면".to_string(),         Kind::Else);
        map
    };
}

