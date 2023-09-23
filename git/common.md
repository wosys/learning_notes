# 常用

## Git创建仓库

***

### git init

新建一个文件夹，在该目录的路径下使用bash命令：

    git init # 初始化
    git status # 查看状态和是否存在.git文件
此时在该文件夹下就会有一个隐藏属性的文件夹.git
**仓库分为工作区，暂存区，提交区**。文件夹即是工作区，现在我们在这个路径下使用bash命令：

    git add [filename] #告诉git开始对哪一些文件进行追踪
    git commit -m '一些注释'
***

### git clone

从现有 Git 仓库中拷贝项目

    git clone <repo> <directory> # 克隆到指定的目录

>git clone git://github.com/schacon/grit.git mygrit
>>表示在当前目录下创建一个名为grit的目录，其中包含一个 .git 的目录，用于保存下载下来的所有版本记录。mygrit参数表示自己定义要新建的项目目录名称

***
配置

    git config --list # 查看
    git config -e    # 编辑，针对当前仓库
    git config -e --global   # 针对系统上所有仓库

    设置提交代码时的用户信息：
    $ git config --global user.name "wintmain"
    $ git config --global user.email 203659850@qq.com

## Git 基本操作

### git add

    git add [file1][file2]… # 添加一个或多个文件到暂存区
    git add [dir] # 添加指定目录到暂存区，包括子目录
    git add . # 添加当前目录下的所有文件到暂存区

### git status

    git status -s # 通常使用-s参数来获得简短的输出结果

### git diff

比较文件在暂存区和工作区的差异
git diff 显示已写入暂存区和已经被修改但尚未写入暂存区文件的区别

    git diff [file] # 显示暂存区和工作区的差异
    git diff --cached/--staged [file]# 显示暂存区和上一次提交(commit)的差异
    git diff [first-branch]...[second-branch] # 显示两次提交之间的差异
    git diff --stat # 显示摘要而非整个diff

### git commit

    git commit /(可选)[file1][file2]... -m [message] # 提交暂存区到本地仓库中
    git commit -a # -a 参数设置修改文件后不需要执行 git add 命令，直接来提交

### git reset

用于回退版本，可以指定退回某一次提交的版本

    git reset [--soft | --mixed | --hard] [HEAD]# 默认为--mixed，可以不用带该参数，用于重置暂存区的文件与上一次的提交(commit)保持一致，工作区文件内容保持不变。

    git reset [HEAD]
    $ git reset HEAD^  # 回退所有内容到上一个版本
    $ git reset 052e   # 回退到指定版本

    git reset --soft HEAD # --soft参数用于回退到某个版本
    $ git reset --soft HEAD~3 # 回退上上上一个版本

    git reset --hard HEAD # --hard 参数撤销工作区中所有未提交的修改内容，将暂存区与工作区都回到上一次版本，并删除之前的所有信息提交
    [谨慎使用 –hard 参数，它会删除回退点之前的所有信息]
    $ git reset –hard HEAD~3  # 回退上上上一个版本
    $ git reset –hard bae128  # 回退到某个版本回退点之前的所有信息。
    $ git reset --hard origin/master    # 将本地的状态回退到和远程的一样

>HEAD说明：
HEAD 表示当前版本
HEAD^ 上一个版本
HEAD^^ 上上一个版本
HEAD^^^ 上上上一个版本
以此类推...
或者：
HEAD~0 表示当前版本
HEAD~1 上一个版本
HEAD^2 上上一个版本
HEAD^3 上上上一个版本
以此类推...

**简而言之，执行 git reset HEAD 以取消之前 git add 添加，但不希望包含在下一提交快照中的缓存**。

### git rm

用于删除文件

    git rm <file> # 将文件从暂存区和工作区中删除
    git rm -f <file> # 删除之前修改过并且已经放到暂存区域
    git rm --cached <file> # 如果想把文件从暂存区域移除，但仍然希望保留在当前工作目录中
    git rm –r [dir] # 递归删除

### git mv

    git mv [file] [newfile] # 用于移动或重命名一个文件、目录或软连接
    git mv -f [file] [newfile] # 如果新但文件名已经存在，但还是要重命名它，可以使用 -f 参数
***

## Git 远程操作

### git remote

    git remote -v # 显示所有远程仓库
    git remote show [remote] # 显示某个远程仓库的信息
    git remote add [shortname] [url] # 添加远程版本库
    git remote rm name  # 删除远程仓库
    git remote rename [old_name] [new_name]  # 修改仓库名

### git fetch

    git fetch # 用于从远程获取代码库
    git merge # 从远端仓库提取数据并尝试合并到当前分支
    # 在执行 git fetch 之后紧接着执行 git merge 远程分支到你所在的任意分支

假设你配置好了一个远程仓库，并且你想要提取更新的数据，你可以首先执行:

    git fetch [alias]
以上命令告诉 Git 去获取它有你没有的数据，然后你可以执行：

    git merge [alias]/[branch]
以上命令将服务器上的任何更新（假设有人这时候推送到服务器了）合并到你的当前分支。

### git pull

用于从远程获取代码并合并本地的版本
git pull 其实就是 git fetch 和 git merge FETCH_HEAD 的简写

    git pull <远程主机名> <远程分支名>:<本地分支名>
    git pull origin master:brantest # 将远程主机 origin 的 master 分支拉取过来，与本地的 brantest 分支合并
    git pull origin master # 如果远程分支是与当前分支合并，则冒号后面的部分可以省略

### git push

用于从将本地的分支版本上传到远程并合并

    git push <远程主机名> <本地分支名>:<远程分支名>
    git push <远程主机名> <本地分支名> # 如果本地分支名与远程分支名相同，则可以省略冒号
    git push --force origin master # 如果本地版本与远程版本有差异，但又要强制推送可以使用 --force 参数
    git push origin --delete master # 删除主机但分支可以使用 --delete 参数

***

## Git查看提交历史

### git log

    git log # 查看历史提交记录
    git log --oneline # 来查看历史记录的简洁的版本
    git log --graph # 查看历史中什么时候出现了分支、合并。以下为相同的命令，开启了拓扑图选项
    git log --reverse --oneline #逆向显示所有日志
    git log --author=wintmain  # 只想查找wintmain的提交日志可以使用命令

    $git log --oneline --before={3.weeks.ago} --after={2010-04-18} --no-merges # 三周前且在四月十八日之后的所有提交, --no-merges 选项以隐藏合并提交

### git blame

    git blame <file> # 查看指定文件的修改记录

## Git 分支管理

使用分支意味着你可以从开发主线上分离开来，然后在不影响主线的同时继续工作

    git branch [branchname] # 创建分支命令
    git checkout [branchname] # 切换分支命令
    git checkout -b [branchname] # 创建新分支并立即切换到该分支下

删除分支

    git branch -d [branchname]（-D强制删除，用于分支没有合并的情况）

当你切换分支的时候，Git 会用该分支的最后提交的快照替换你的工作目录的内容， 所以多个分支不需要多个目录。

    git merge # 合并分支命令

发生合并冲突的时候，需对文件修改
**要用 git add 告诉 Git 文件冲突已经解决**

***

## Git 标签

如果你达到一个重要的阶段，并希望永远记住那个特别的提交快照，你可以使用 git tag 给它打上标签。

    git tag -a XXX # -a 意为"创建一个带注解的标签"

    git tag # 查看所有标签
    git tag -a <tagname> -m "一些信息" # 指定标签信息命令
