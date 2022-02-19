#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <iterator>
#include <regex>

std::vector<std::string> read_file(const std::string &file_name){
    std::vector<std::string> text;
    std::string line;
    std::string path = "../../texts/" + file_name;
    std::ifstream file_read(path);
    while (std::getline(file_read,line)){
        if (!line.empty()){
            text.push_back(line);
        }
    }
    file_read.close();
    return text;
}

int main() {
//    std::string s = "akjsdh laksd, asdlk askld       alksdalksdj asd a";

//    std::stringstream ss;
//    ss << s;
//    std::string signs = ".,/?!";
//    std::vector<std::string> s_vec;
//    while(!ss.eof()){
//        ss >> s;
//        if (signs.find(s[s.size()-1]) != signs.npos) s.pop_back();
//        s_vec.push_back(s);
//    }
    std::string s = "Some people, when confronted 123-46-57 with a problem, think "
                    "\"I know, I'll use regular expressions.\" "
                    "Now they have two problems.";

//    std::regex self_regex("REGULAR EXPRESSIONS",
//                          std::regex_constants::ECMAScript | std::regex_constants::icase);
//    if (std::regex_search(s, self_regex)) {
//        std::cout << "Text contains the phrase 'regular expressions'\n";
//    }

    std::regex word_regex("(\\w+)");
    auto words_begin =
            std::sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = std::sregex_iterator();

    std::cout << "Found "
              << std::distance(words_begin, words_end)
              << " words\n";

    const int N = 6;
    std::cout << "Words longer than " << N << " characters:\n";
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
//        if (match_str.size() > N) {
            std::cout << "  " << match_str << '\n';
//        }
    }

    std::regex long_word_regex("(\\w{7,})");
    std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
    std::cout << new_s << '\n';
    return 0;
}
