# File Encryption and Decryption Tool

This project is a simple file encryption and decryption tool implemented in C++. It allows users to securely encrypt and decrypt files using a randomly generated key. The key is stored in a file named `secret.key`, which is used for both encryption and decryption processes.

## Features

- Generate a random encryption key.
- Encrypt files using the generated key.
- Decrypt files using the same key.
- Simple command-line interface for user interaction.
- Key management through a dedicated key file.
- Optional GUI using Python and `tkinter`.
- further working of cpp code was mentioned in working.txt file .

## Requirements

- C++11 or later
- A C++ compiler (e.g., g++, clang++)
- Python 3.x (for the GUI)
- `tkinter` library (comes pre-installed with Python)

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/yourusername/your-repo-name.git

cd your-repo-name

2. Compile the C++ Code
Make sure you have a C++ compiler installed. You can compile the C++ code using the following command:

  bash :-
g++ -o file_encryption_decryption main.cpp
Replace main.cpp with the name of your C++ source file.

3. Run the Program
You can run the compiled executable from the command line:

  bash :-
./file_encryption_decryption

4. Using the GUI (Optional)
To use the GUI version of the tool, you need to have Python installed. Follow these steps:

Install Python if you haven't already.
Ensure you have the tkinter library (usually included with Python).
Update the CPP_EXECUTABLE variable in the Python script to point to your compiled C++ executable.

Run the Python script:
   bash :-
python gui.py

5. Menu Options
When you run the program, you will see the following menu:

File Encryption and Decryption Tool
1. Generate Encryption Key
2. Encrypt File
3. Decrypt File
4. Exit
Option 1: Generate a new encryption key and save it to secret.key.
Option 2: Encrypt a file by providing its path.
Option 3: Decrypt a file by providing its path.
Option 4: Exit the program.
Important Notes
The secret.key file is crucial for the encryption and decryption processes. Keep it secure and do not lose it; otherwise, you will not be able to decrypt your files.
Ensure that the files you want to encrypt or decrypt are accessible and not in use by other programs.
Key Usage
Generating the Key: When you select the option to generate a key, the program creates a random key and saves it to secret.key.
Loading the Key: When you choose to encrypt or decrypt a file, the program loads the key from secret.key.
Encrypting a File: The program reads the file's contents, applies the XOR operation with the key, and writes the encrypted data back to the file.
Decrypting a File: The decryption process is identical to the encryption process because XOR is a symmetric operation.
License
This project is licensed under the MIT License. See the LICENSE file for more details.

Acknowledgments
This project was inspired by the need for simple file encryption solutions.
Special thanks to the open-source community for their contributions and resources.

### Instructions for Use

1. **Replace Placeholder Text**: Make sure to replace `yourusername`, `your-repo-name`, `Your Name`, and `Your Email` with your actual GitHub username, repository name, and your contact information.
2. **Add Additional Sections**: If you have more features, installation instructions, or usage examples, feel free to add them to the README.
3. **Save the File**: Save this content in a file named `README.md` in the root directory of your project.
