# Photo-Encryption
 created by: Brandon Nguyen

![decode](decode.PNG)

## Summary :framed_picture:

This project is a Photo-Encryption program in C++ that uses a Fibonacci Linear Feedback Shift Register algorithm (LFSR).
The program will generate random bits by simulating a LFSR and will be used to create a simple encryption device for digital photos. In the latest version of this project, we completed the full program with the help of the LFSR.

## Features :tada:

This program takes in any user image and encrypts the image into random colorful pixels. If a user inputs the encrypted image, it outputs the original image.

## Build :hammer_and_wrench:

Clone the repository:

```
git clone https://github.com/ThatGuyHieu/Photo-Encryption.git
cd Photo-Encryption
make
```

## Run :runner:

```
./Encrypt < input image > < output image > < 16 size bitstring >
example:
./Encrypt input-file.png output-file.png 1011011000110110
```



