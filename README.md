# Basic Encryption Algorithm in C

## Project Overview
This project demonstrates a basic encryption algorithm implemented in the C programming language. It was developed as a learning exercise to deepen my understanding of C, focusing on file handling, string manipulation, and basic cryptographic concepts. The program:

1. Encrypts user-provided text using a random key and a random shift value.
2. Stores the encrypted text, along with its corresponding key and shift value, in an external CSV file for future reference.
3. Provides functionality to display stored encrypted texts and their associated keys.

---

## Features

- **Random Key Generator**: Generates a random substitution cipher key using the Fisher-Yates shuffle algorithm.
- **Random Shift Generator**: Produces a random shift value to enhance the encryption process.
- **Encryption Algorithm**: Applies the generated key and shift value to encrypt user-provided text.
- **File Storage**: Saves encrypted text, key, and shift in a CSV file (`encryptions.csv`) for tracking.

---

## How to Use

1. **Compile the Code**:
   Use a C compiler (e.g., GCC) to compile the program:
   ```bash
   gcc -o encryption_program encryption_program.c
   ```

2. **Run the Program**:
   Execute the compiled program:
   ```bash
   ./encryption_program
   ```

3. **Provide Input**:
   - Enter text to encrypt when prompted.
   - Type `dictionary` to display all stored encrypted texts and their corresponding keys.

4. **Check Output**:
   - The encrypted text will be displayed on the console.
   - Encrypted text, key, and shift will be stored in the `encryptions.csv` file.

---
## Future Prospects

1. **Advanced Encryption Algorithms**:
   - Explore more robust encryption techniques (AES, RSA) to enhance security.
   - Implement hybrid cryptographic methods.

2. **Improved Storage System**:
   - Transition from a CSV file to a secure database for better scalability and encryption of stored data.
   - Implement access controls for enhanced data protection.

3. **Error Handling and Validation**:
   - Improve input validation to handle edge cases.
   - Add detailed error messages for better debugging.

4. **Cross-Platform Support**:
   - Optimise the program for compatibility across different operating systems.

---
## License
This project is open-source and available under the MIT License.

