# Git

版本管理工具

## 1 概念介绍

### 1.1 git对象模型

Git世界里有四种类型的对象分别是`blob、tree、commit、tag`

`blob`用来存储文件数据，通常是一个文件。
`tree`有点像一个目录，它管理一些`tree`或是`blob` (就像文件和子目录)
`commit`对象指向一个`tree`对象，他用来表示某次提交时的状态，它包括一些关于时间点的元数据，如时间戳、最近一次提交的作者、指向上次提交(commits) 的指针等等。
`tag`对象也称为里程碑，用来**表示某个重要的commit**。标记tag对象后就可以直观的通过tag名称来找到这个commit。

几乎所有的Git功能都是使用这四个简单的对象类型来完成的，下图示中， 绿色表示commit对象，蓝色表示tree对象，红色表示blob对象，灰色表示分支。

一个commit对象包含了必要的提交者信息、一个**指向父提交的parent指针**（除了首次提交）和一个**指向tree对象的tree指针**。一个tree对象中保存了**目录结构信息和若干指向blob对象的指针**。Blob对象中**保存着实际的数据内容**。

![Untitled](pics/Untitled.png)

经过多次提交以后，就形成了**一条commit对象链表**。这样，就出现了**分支**的概念。

![Untitled](pics/Untitled%201.png)

分支就是**指向commit对象链表中最近一次commit对象的指针**。这样的设计使得分支非常的轻量，创建和删除分支的代价都非常小。

Tag对象：我们可以用git tag不带任何参数创建一个标签指向某个提交，方便以后引用

`git tag stable-1 1b2e1d63ff`

这样，我们可以用`stable-1`作为提交`[1b2e1d63ff]`的代称(refer) 。如果想为一个标签(tag) 添加注释，那么我们就需要创建一个真正的标签对象。

可以用`-a`参数来创建一个标签对象，如果要为这个标签对象添加注释则输入`-m`参数。

当这样的一条命令执行后，一个新的对象被添加到Git对象库中，并且**标签引用就指向了一个标签对象，而不是指向一个提交**

`git tag -a stable-1 1b2e1d63ff`

### 1.2 索引对象的方法

使用git的过程中，经常需要制定某个提交或者分支进行某项操作。对于每个commit对象，都有唯一的40个字符长度的SHA-1码表示其身份，称为`<commit id>`。实际操作过程中有几种简便的方法可以容易的索引到需要的提交。

<commit id>虽然有40个字符的长度，但是实际使用中**只需要填入SHA-1码的前几位保证没有重复的项**，那么git就可以正确的找到这个commit对象，**一 般情况下8-10个字符已经足够保证唯一性了**。

例如，以下两条命令是完全等价的：

![Untitled](pics/Untitled%202.png)

1. HEAD头指针，git会自动创建一个HEAD头指针，**指向当前分支的最新一个提交**，每次提交或者reset后HEAD会随着分支向前或向后移动。
2. 祖先引用，符号`^`表示父提交(parrent) ，`HEAD^`表示倒数第二次提交，`HEAD^^`表示倒数第三次提交。若回溯的次数比较大，使用^就很不方便了，可以使用<commit id>~n形式表示commit的第n次祖先提交，例如：`HEAD~3`等价于`HEAD^^^`。
3. 使用`<commit id>:PATH/filename`可以**访问到某个提交中的某个文件**`git show HEAD^:drivers/usb/dwc_otg/dwc_otg_driver.c`这个命令可以显示出倒数第二次提交中的dwc_otg_driver.c 文件的内容
4. 提交范围：双点语法，这种语法主要是让Git区分出可从一个分支中获得而不能从另一个分支中获得的提交。

![Untitled](pics/Untitled%203.png)

![Untitled](pics/Untitled%204.png)

这句话的意思是**列出所有experiment 分支中包含但是master分支中不包含找到的log**

三点语法：**表示两个分支的所有不共享的分支的集合**，以上面分支模型为例

![Untitled](pics/Untitled%205.png)

显示的是C，D，E，F

### 1.3 git config参数设置

![Untitled](pics/Untitled%206.png)

设置用户信息，git 要求每次提交必须有相应的用户名和邮箱信息。加上`--grobal`参数会将用户名信息写入到`.gitconfig`目录下保存，作为全局设置。若不加则相关信息保存在当前仓库中的`.git/config` 文件，有效范围是当前git仓库中的项目。

`git config --global color.ui true`开启彩色ui效果

`git config --global diff.tool vimdiff`设置差异比较工具为vim

`git config --add core.filemode false`不检查文件模式差别

```
git config --list # 查看
git config -e    # 编辑，针对当前仓库
git config -e --global   # 针对系统上所有仓库
```

### 1.4 git alise 命名别名

提供命令缩写功能，可以自行设置将冗长的命令简化，提高工作效率。

在`.gitconfig`文件中添加`[alise]`字段，格式：

![Untitled](pics/Untitled%207.png)

用命令行的方式同样的以实现命名别名的功能如第一个：`git config --global alise.st status`

### 1.5 gitignore 忽略文件

有些文件无需纳入Git的管理，也不希望它们总出现在未跟踪文件列表。通常都是些自动生成的文件，比如日志文件，或者编译过程中创建的临时文件等。

我们可以创建一个名为.gitignore的文件，列出要忽略的文件模式。

文件.gitignore 的格式规范：

- 空行或者以注释符号#开头的行都会被Git忽略
- 可以使用通配符
- 匹配模式最后跟反斜杠（/）说明要忽略的是**目录**。
- 要忽略指定模式以外的文件或目录，可以在模式前加上**!**取反。
- .gitignore 可以放在任何目录中，其**作用范围是其所处的目录及其子目录**

## 2 常用命令和技巧

### 2.1 git init和git clone

`git init`初始化一个版本库，新建一个文件夹，在该目录的路径下使用bash命令：

```
git init # 初始化
git status # 查看状态和是否存在.git文件
```

此时在该文件夹下就会有一个隐藏属性的文件夹.git。**仓库分为工作区，暂存区，提交区**。文件夹即是工作区，现在我们在这个路径下使用bash命令：

```
git add [filename] #告诉git开始对哪一些文件进行追踪
git commit -m '一些注释'
```

`git clone`从现有 Git 仓库中拷贝项目

```
git clone <repo> <directory> # 克隆到指定的目录
```

> git clone git://github.com/schacon/grit.git mygrit
> 
> 
> > 表示在当前目录下创建一个名为grit的目录，其中包含一个 .git 的目录，用于保存下载下来的所有版本记录。mygrit参数表示自己定义要新建的项目目录名称
> > 

### 2.2 git log

显示日志范围、分支图显示、显示最近几条日志、显示每次更改概要

`git log -n`显示最近的n次提交

`--graph`参数可以以图形方式查看日志
`--oneline`只显示一行的简要提交信息
`--stat`显示修改的文件

![Untitled](pics/Untitled%208.png)

Ubuntu下可以使用图形化的软件gitk，便于查看版本库情况：`$ gitk`

### 2.3 git branch与git checkout

新功能开发、Bug修复，这些事情都可以先在本地开local branch做，而不需要立即Push 分享给别人。

`git branch`查看本地分支列表，**带有*的是当前工作分支**

`git branch -r` 查看远程分支

建立本地local branch：`git branch <new_branch_name>`

分支改名(如果有同名会失败，改用-M可以强制覆盖)`git branch -m <old_name> <new_name>`

**切换分支会丢失工作区和暂存区中的修改**，所以进行checkout之前要先用`git stash save`暂存未提交的数据或`git commit`提交新版本，如果暂存区和工作去中还存在未提交或暂存的数据，`git checkout`会报错无法继续

`git checkout <branch_name>`

本地建立branch并立即checkout切换过去`git checkout -b <new_branch_name>`

删除local branch：`git branch -D <branch_name>`

开Branch最大的好处除了可以不影响stable 和其他分支版本的开发。同时git的设计将分支设计的非常轻量，建立或删除分支的代价非常小、速度非常快。

### 2.4 git diff

用来比较任意两个对象

命令比较的是工作区和暂存区中文件的区别。需要比较版本库和暂存区的区别

`git diff --cached <commit id>`

这里的commit id默认为HEAD。比较工作区和版本库中最新一个提交的区别命令是

`git diff HEAD`

如果不是查看每个文件的详细差别，而是统计一下有哪些文件被改动，有多少行被改动，就可以使用`--stat`参数。

### 2.5 git fetch与git pull

都是**从远程版本库**取回最新代码，区别在于pull会自动merge而fetch不会。

git fetch回来的代码会更新到`origin/HEAD`分支。Git pull相当于以下两条命令的结合

`git fetch`

`git merge origin/HEAD`

如果本地已经有自己的提交，又要获取服务器的最新代码，使用带rebase功能的pull，而不使用默认的merge：`git pull --rebase`

### 2.6 git merge

将版本合并。若不成功，将不会自动产生新的commit，合并后的代码进入暂存区。

合并过程会产生冲突，需要手工处理，处理过的冲突文件需要用git add加入暂存区后才可以提交新版本。

![Untitled](pics/Untitled%209.png)

`git checkout mywork`
`git merge origin`

![Untitled](pics/Untitled%2010.png)

### 2.7 git rebase

`git checkout mywork
git rebase origin`

![Untitled](pics/Untitled%2011.png)

比对上面两幅图。若在执行rebase后想要删除无用的提交**c5、c6**只要执行垃圾收集命令`git gc` (garbage collection)，git 会自动处理掉无用的提交

在rebase的过程中，也会出现冲突。在这种情况下，git 会停止rebase 并会让你去解决冲突，在解决完冲突后，用`git -add`命令 去更新这些内容的暂存区，然后无需执行git-commit，只要执行：`git rebase --continue`

这样git会继续rebase的过程。在任何时候，可以用`git rebase --abort`命令在终止rebase的过程，并且"'mywork"分支会回到rebase开始前的状态。

使用`git rebase -i <commit id>`修改本地多个补丁，效率很高

### 2.8 git reset与git revert

reset可以很灵活的改变本地版本库的历史，但是这些历史才做的更改只能是针对自己的版本库，而无法修改他人的版本库，在实际情况下要修改一个历史错误的正确方法是使用`git revert`命令进行一次反转提交。即重新进行一次提交，提交内容是**错误历史提交的反向修改**。这样版本库向前推进而不是倒退，当他人同步本地版本库就会将这次反转提交一起同步走也就起到了修复错误的作用。

![Untitled](pics/Untitled%2012.png)

![Untitled](pics/Untitled%2013.png)

### 2.9 git stash

用于**存储未提交的变更**。工作中难免会遇到这样的情况。手头的工作进行到一半，突然有一个紧急的
bug需要修补，此时将会处于这样情景：手头的工作尚未完成不能随意提交，bug 又需要切换到先前的稳定分支进行修复，工作就这样被打断了。这时应该选择`git stash`命令暂存手头的工作。

![Untitled](pics/Untitled%2014.png)

### 2.10 git remote管理远程版本库

增加远程版本库`git remote add <name> <url>`

对应的rm可以删除远程版本库`git remote rm <name>`

显示远程版本库的详细信息`git remote -V`

### 2.11 git 冲突处理

当两个分支修改了**同一个文件的相同部分时**git无法判断需要采用那个版本的修改，就会中断正在进行的合并过程

git修改了遇到冲突的文件，在工作目录中加入的文件里加入冲突提示符(<<==>>)， 需要手工修改解决冲突后将这个文件用`git add`命令加入暂存区，注意，修改时一定要清除冲突提示符，加入暂存区后可以使用`git commit`或者`git rebase --continue`命令继续。当有文件冲突时，使用`git status`查看状态会发现，冲突的文件被标记为`Unmerged` 状态

冲突内容较多时，图像工具：`git merge tool`

### 2.12 git reflog可以查看所有分支的所有操作记录

git reflog 命令可以用来查看所有的分支变动操作记录的操作包括rebase、merge、checkout、 commit 等。

git reflog的一个重要的用途：假如不小心错误的修改了分支历史如进行rebase操作导致某些版本号丢失，可以使用git reflog找回，即使这个版本号在版本库中已经找不到了(用git log)它实际上仍然有效，可以用`git rebase <commit id>`来恢复。

### 2.13 git 库编辑

![Untitled](pics/Untitled%2015.png)

### 2.14 git commit

`git add`或`git rm`后需要使用`git commit`命令将暂存区内容提交到版本库中

带签名提交：-s

修改最后一个提交，如果一个刚刚提交的commit觉得还有问题，需要改进，那么可以修改内容后使用如下命令重新提交，这个命令也可以同时修改commit message：`git commit -amend`

### 2.15 git push

![Untitled](pics/Untitled%2016.png)

### 2.16 git format-patch

![Untitled](pics/Untitled%2017.png)

### 2.18 git am

![Untitled](pics/Untitled%2018.png)

### 2.19 git archive

![Untitled](pics/Untitled%2019.png)

## 示例

![Untitled](pics/Untitled%2020.png)