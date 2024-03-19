use std::fs::File;
use std::io::{BufRead, BufReader};
use std::path::Path;
use define::kind::Token;
use define::token::Kind;

enum CharType {
    Unknown,
    WhiteSpace,
    NumberLiteral,
    StringLiteral,
    IdentifierAndKeyword,
    OperatorAndPunctuator,
}

fn get_char_type(c: char) -> CharType {
    match c {
        ' ' | '\t' | '\r' | '\n' => CharType::WhiteSpace,
        '0'..='9' => CharType::NumberLiteral,
        '\'' | '\"' => CharType::StringLiteral,
        '가'..='힣' => CharType::IdentifierAndKeyword,
        _ => CharType::Unknown,
    }
}

fn is_char_type(c: char, kind: CharType) -> bool {
    match kind {
        CharType::NumberLiteral => c == '.' || ('0'..='9').contains(&c),
        CharType::StringLiteral => c != '\'' && c != '\"',
        CharType::IdentifierAndKeyword => ('0'..='9').contains(&c) || ('가'..='힣').contains(&c),
        _ => false,
    }
}

fn scan_number_literal(input: &mut std::str::Chars) -> Token {
    let mut value = String::new();
    while let Some(c) = input.next() {
        if is_char_type(c, CharType::NumberLiteral) {
            value.push(c);
        } else {
            break;
        }
    }
    Token::new(Kind::NumberLiteral, value)
}

fn scan_string_literal(input: &mut std::str::Chars) -> Token {
    let mut value = String::new();
    input.next(); // Skip the opening quote
    while let Some(c) = input.next() {
        if is_char_type(c, CharType::StringLiteral) {
            value.push(c);
        } else if c != '\'' && c != '\"' {
            println!("문자열이 종료되지 않았습니다.");
            std::process::exit(1);
        } else {
            break;
        }
    }
    Token::new(Kind::StringLiteral, value)
}

fn scan_identifier_and_keyword(input: &mut std::str::Chars) -> Token {
    let mut value = String::new();
    while let Some(c) = input.next() {
        if is_char_type(c, CharType::IdentifierAndKeyword) {
            value.push(c);
        } else {
            break;
        }
    }
    // Determine if the identifier is a keyword
    let kind = match value.as_str() {
        // Add more keyword patterns here if needed
        "if" => Kind::If,
        "else" => Kind::Else,
        _ => Kind::Identifier,
    };
    Token::new(kind, value)
}

fn scan_files(file_paths: Vec<&str>) -> String {
    let mut file_content = String::new();
    for file_path in file_paths {
        let path = Path::new(file_path);
        let file = match File::open(&path) {
            Ok(file) => file,
            Err(_) => {
                eprintln!("Error opening file: {}", file_path);
                return String::new();
            }
        };
        let reader = BufReader::new(file);
        for line in reader.lines() {
            if let Ok(line) = line {
                file_content.push_str(&line);
                file_content.push('\n');
            }
        }
    }
    file_content
}

fn scan_tokens(file_paths: Vec<&str>) -> Vec<Token> {
    let file_content = scan_files(file_paths);
    let mut tokens = Vec::new();
    let mut input = file_content.chars().peekable();

    while let Some(&c) = input.peek() {
        match get_char_type(c) {
            CharType::WhiteSpace => {
                input.next();
            }
            CharType::NumberLiteral => {
                tokens.push(scan_number_literal(&mut input));
            }
            CharType::StringLiteral => {
                tokens.push(scan_string_literal(&mut input));
            }
            CharType::IdentifierAndKeyword => {
                tokens.push(scan_identifier_and_keyword(&mut input));
            }
            CharType::Unknown => {
                input.next();
            }
            _ => {}
        }
    }

    tokens.push(Token::new(Kind::EndOfCode, String::new()));
    tokens
}

fn main() {
    let file_paths = vec!["path/to/your/file1.txt", "path/to/your/file2.txt"];
    let tokens = scan_tokens(file_paths);
    println!("{:#?}", tokens);
}
