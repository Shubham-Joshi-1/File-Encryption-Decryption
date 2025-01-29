import tkinter as tk
from tkinter import filedialog, messagebox
import subprocess

# Path to the C++ executable
CPP_EXECUTABLE = "main.exe" 

class FileEncryptionApp:
    def __init__(self, master):
        self.master = master
        master.title("File Encryption and Decryption Tool")

        self.label = tk.Label(master, text="File Encryption and Decryption Tool")
        self.label.pack()

        self.generate_key_button = tk.Button(master, text="Generate Encryption Key", command=self.generate_key)
        self.generate_key_button.pack()

        self.encrypt_button = tk.Button(master, text="Encrypt File", command=self.encrypt_file)
        self.encrypt_button.pack()

        self.decrypt_button = tk.Button(master, text="Decrypt File", command=self.decrypt_file)
        self.decrypt_button.pack()

        self.exit_button = tk.Button(master, text="Exit", command=master.quit)
        self.exit_button.pack()

    def generate_key(self):
        try:
            result = subprocess.run([CPP_EXECUTABLE, "1"], capture_output=True, text=True, check=True)
            messagebox.showinfo("Success", result.stdout.strip())
        except subprocess.CalledProcessError as e:
            messagebox.showerror("Error", e.stderr.strip())

    def encrypt_file(self):
        file_path = filedialog.askopenfilename()
        if file_path:
            try:
                result = subprocess.run([CPP_EXECUTABLE, "2", file_path], capture_output=True, text=True, check=True)
                messagebox.showinfo("Success", result.stdout.strip())
            except subprocess.CalledProcessError as e:
                messagebox.showerror("Error", e.stderr.strip())

    def decrypt_file(self):
        file_path = filedialog.askopenfilename()
        if file_path:
            try:
                result = subprocess.run([CPP_EXECUTABLE, "3", file_path], capture_output=True, text=True, check=True)
                messagebox.showinfo("Success", result.stdout.strip())
            except subprocess.CalledProcessError as e:
                messagebox.showerror("Error", e.stderr.strip())

if __name__ == "__main__":
    root = tk.Tk()
    app = FileEncryptionApp(root)
    root.mainloop()