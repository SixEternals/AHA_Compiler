#include "CharStream.h"
#include "midend/IRVisitor.hpp"
#include "SysYLexer.h"
#include "SysYParser.h"
#include <iostream>
#include <midend/IRContext.hpp>
using namespace antlr4;

int main(int argc, char **argv) {
    // 性能测试: aha -S -o add.s add.sy
    if (argc < 1) {
        std::cout << "input path is required" << '\n';
        return 1;
    }
    // std::string dest = argv[3];   // 输出文件名
    // std::string source = argv[4]; // 输入 SysY 文件名
    std::string dest;
    std::string source;

    // 简单解析命令行参数（无 getopt）
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-o" && i + 1 < argc) {
            dest = argv[++i];
        } else if (arg[0] != '-') {
            source = arg;
        }
    }
    if (source.empty() || dest.empty()) {
        std::cerr << "Missing required -o or source file" << std::endl;
        return 1;
    }
    std::cout << "source: " << source << '\n' << "dest: " << dest << '\n';

    for (int i = 0; i < argc; ++i) {
        std::cout << i << ": " << argv[i] << '\n';
    }

    // 创建context单例
    IRContext &context = IRContext::getInstance();

    std::ifstream inputFile(source);
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    ANTLRInputStream input(buffer.str());
    SysYLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    SysYParser parser(&tokens);
    auto tree = parser.program();
    IRVisitor visitor{source};
    visitor.visitProgram(tree);

    std::cout << "Parsing and visiting completed successfully." << '\n';
    return 0;
}
