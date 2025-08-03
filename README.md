# 自制编译器 My Custom Compiler

特点如下：
  该编译器模仿 LLVM 架构，采用 LLVM IR 格式。
  其前端开发得到了 ANTLR4 的辅助，中端以 LLVM IR 形式呈现，后端则针对 RISC-V。后续还计划继续开发 ARM 后端。

Attributes:
  Based on the LLVM architecture, using the LLVM IR format.
  The front end is developed with the help of ANTLR4, the middle end is in the form of LLVM IR, and the back end targets RISC-V. It is anticipated that the development of the ARM back end will continue.