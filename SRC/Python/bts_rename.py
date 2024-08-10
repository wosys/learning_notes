import os
import tkinter as tk
from tkinter import filedialog

# bts v1，主要是修改zip文件的名字，替换其中的特殊字符
class MainWindow(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master # type: ignore
        self.file_path = ""

        # 创建标签和输入框控件
        self.instruction_label = tk.Label(self, text="Fingerprint（刷机后得到）：")
        self.string_input = tk.Entry(self)
        self.old_filename_label = tk.Label(self, text="")
        self.new_filename_label = tk.Label(self, text="")
        self.select_button = tk.Button(self, text="选择文件（zip文件）", command=self.select_file)
        self.replace_button = tk.Button(self, text="最后点击替换~", command=self.replace_file_name)

        # 初始化界面
        self.init_ui()

    def init_ui(self):
        # 设置标签和输入框控件的位置和参数
        self.instruction_label.grid(row=0, column=0, padx=10, pady=10, sticky="w")
        self.string_input.grid(row=0, column=1, padx=10, pady=10)

        # 设置文件选择按钮的位置和参数
        self.select_button.grid(row=1, column=0, columnspan=2, padx=10, pady=10)

        # 设置文件名标签和替换按钮的位置和参数
        old_label = tk.Label(self, text="原始zip文件名：")
        old_label.grid(row=2, column=0, padx=10, pady=10, sticky="w")
        self.old_filename_label.grid(row=2, column=1, padx=5, pady=10, sticky="w")
        new_label = tk.Label(self, text="替换后的文件名：")
        new_label.grid(row=3, column=0, padx=10, pady=5, sticky="w")
        self.new_filename_label.grid(row=3, column=1, padx=10, pady=10, sticky="w")
        self.replace_button.grid(row=4, column=0, columnspan=2, padx=10, pady=10)


    def select_file(self):
        # 使用文件选择对话框选择文件
        file_path = filedialog.askopenfilename()
        if file_path:
            # 保存选中的文件路径，并在界面上显示当前文件名
            self.file_path = file_path
            self.old_filename_label["text"] = os.path.basename(file_path)

    def replace_file_name(self):
        if self.file_path:
            # 获取用户输入的字符串，替换文件名并重命名
            old_filename = os.path.basename(self.file_path)
            new_filename = self.string_input.get().replace("/", "~").replace(":", "~")
            new_filename = new_filename + ".zip"
            new_file_path = os.path.join(os.path.dirname(self.file_path), new_filename)
            os.rename(self.file_path, new_file_path)
            self.new_filename_label["text"] = new_filename


if __name__ == "__main__":
    # 创建窗口并设置参数
    root = tk.Tk()
    root.title("BTS送测文件名修改 v1.0")
    root.geometry("600x250")

    # 创建并显示主窗口
    main_window = MainWindow(root)
    main_window.pack(expand=True, fill="both")

    root.mainloop()
