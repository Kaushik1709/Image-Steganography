\# Image Steganography



\## Overview

A C-based steganography tool that hides secret text files 

inside BMP images using the LSB (Least Significant Bit) 

technique — without visibly altering the image.



\## Objective

The objective of this project is to implement a steganography 

tool in C that hides secret text files inside BMP images using 

the Least Significant Bit (LSB) technique. The tool encodes 

secret data bit by bit into pixel bytes of the image without 

visibly altering it, and decodes the hidden data back to 

reconstruct the original file.



\## Features

\- Encode secret text files into BMP images

\- Decode hidden messages from stego images

\- Magic string verification to detect steganographed images

\- Encodes file extension and size for accurate reconstruction



\## Files

| File | Description |

|------|-------------|

| `common.h` | Magic string definition |

| `types.h` | Custom types and enums |

| `encode.h` | EncodeInfo struct and function declarations |

| `decode.h` | DecodeInfo struct and function declarations |

| `encode.c` | All encoding logic |

| `decode.c` | All decoding logic |

| `main.c` | Entry point with argument parsing |



\## Compilation

```bash

gcc main.c encode.c decode.c -o stego

```



\## Usage

```bash

\# Encode

./stego -e beautiful.bmp secret.txt Output.bmp



\# Decode

./stego -d Output.bmp decoded\_file

```



\## Tech Stack

\- Language: C

\- Format: BMP (24-bit Bitmap)

\- Technique: LSB Steganography

\- Concepts: Bit manipulation, Binary File I/O, BMP parsing

