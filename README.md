# UNP

##编译流程
- autoscan：生成`configure.scan`
- mv configure.scan configure.ac
- 编辑configure.ac（加入**AM_INIT_AUTOMAKE**）
- aclocal：利用`configure.ac`生成一些宏
- autoheader:生成`config.h.in`
- autoconf:生成可执行文件`configure`
- 新建并编辑`Makefile.am`
- automake --add-missing：生成`makefile.in`
- ./configure:生成头文件`config.h`以及`makefile`
