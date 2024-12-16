# NIBWD

Micro-tool that converts an image to grayscale and applies Floyd-Steinberg dithering to it in order to effectively convert it to monochrome. The result file is stored as a lossless BMP that can be easily further processed.

## Requirements

- **GCC**: Ensure you have GCC installed to compile the program.
- **Make**: Use the `make` utility to build the program.

## Installation

1. **Clone the Repository**:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```

2. **Build the Program**:
   Use the `make` command to compile the program in debug mode:
   ```bash
   make debug
   ```

## Usage

- Run the compiled program:
  ```bash
  ./out/debug/nibwd image.png
  ```

## Contributing

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [stb_image](https://github.com/nothings/stb) - Single-file public domain libraries for C/C++.
- [stb_image_write](https://github.com/nothings/stb) - Single-file public domain libraries for C/C++.