#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *b64_encode(const unsigned char *in, size_t len, size_t *out_len);
size_t b64_encoded_size(size_t inlen);

int main()
{
    const char jpeg_bin[] = {0xFF,0xD8,0xFF,0xE0,0x00,0x10,0x4A,0x46,0x49,0x46,0x00,0x01,0x01,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0xFF,0xDB,0x00,0x43,0x00,0x10,0x0B,0x0C,0x0E,0x0C,0x0A,0x10,0x0E,0x0D,0x0E,0x12,0x11,0x10,0x13,0x18,0x28,0x1A,0x18,0x16,0x16,0x18,0x31,0x23,0x25,0x1D,0x28,0x3A,0x33,0x3D,0x3C,0x39,0x33,0x38,0x37,0x40,0x48,0x5C,0x4E,0x40,0x44,0x57,0x45,0x37,0x38,0x50,0x6D,0x51,0x57,0x5F,0x62,0x67,0x68,0x67,0x3E,0x4D,0x71,0x79,0x70,0x64,0x78,0x5C,0x65,0x67,0x63,0xFF,0xDB,0x00,0x43,0x01,0x11,0x12,0x12,0x18,0x15,0x18,0x2F,0x1A,0x1A,0x2F,0x63,0x42,0x38,0x42,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0xFF,0xC0,0x00,0x11,0x08,0x00,0x80,0x00,0x80,0x03,0x01,0x22,0x00,0x02,0x11,0x01,0x03,0x11,0x01,0xFF,0xC4,0x00,0x1F,0x00,0x00,0x01,0x05,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0xFF,0xC4,0x00,0xB5,0x10,0x00,0x02,0x01,0x03,0x03,0x02,0x04,0x03,0x05,0x05,0x04,0x04,0x00,0x00,0x01,0x7D,0x01,0x02,0x03,0x00,0x04,0x11,0x05,0x12,0x21,0x31,0x41,0x06,0x13,0x51,0x61,0x07,0x22,0x71,0x14,0x32,0x81,0x91,0xA1,0x08,0x23,0x42,0xB1,0xC1,0x15,0x52,0xD1,0xF0,0x24,0x33,0x62,0x72,0x82,0x09,0x0A,0x16,0x17,0x18,0x19,0x1A,0x25,0x26,0x27,0x28,0x29,0x2A,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xBA,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFF,0xC4,0x00,0x1F,0x01,0x00,0x03,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0xFF,0xC4,0x00,0xB5,0x11,0x00,0x02,0x01,0x03,0x03,0x02,0x04,0x03,0x05,0x05,0x04,0x04,0x00,0x00,0x01,0x7D,0x01,0x02,0x03,0x00,0x04,0x11,0x05,0x12,0x21,0x31,0x41,0x06,0x13,0x51,0x61,0x07,0x22,0x71,0x14,0x32,0x81,0x91,0xA1,0x08,0x23,0x42,0xB1,0xC1,0x15,0x52,0xD1,0xF0,0x24,0x33,0x62,0x72,0x82,0x09,0x0A,0x16,0x17,0x18,0x19,0x1A,0x25,0x26,0x27,0x28,0x29,0x2A,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xBA,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFF,0xDA,0x00,0x0C,0x03,0x01,0x00,0x02,0x11,0x03,0x11,0x00,0x3F,0x00,0xAF,0x1C,0x8C,0xC7,0xE7,0x38,0x19,0xEE,0x3F,0xCF,0xF9,0xA1,0x8E,0x1F,0xE5,0x18,0xFA,0x0E,0xBF,0xE7,0xFC,0xD3,0x90,0x90,0x33,0x23,0x1E,0x7F,0xBB,0xC8,0x3F,0xE7,0xFC,0xD3,0xC0,0x56,0xCF,0x94,0x30,0x7B,0x1F,0xF3,0xFE,0x6B,0x8F,0xFC,0xFF,0x00,0x9F,0xF3,0x5D,0x5F,0xE7,0xFC,0xFF,0x00,0x9A,0x55,0x65,0x60,0x32,0x9C,0xFA,0xFF,0x00,0x9F,0xF3,0x51,0x4A,0x83,0xAB,0x06,0x52,0x3A,0x1E,0xA3,0xFC,0xFF,0x00,0x9A,0xB1,0xE5,0x83,0x8D,0xEC,0x09,0xF4,0x38,0xFF,0x00,0x3F,0xE6,0xA1,0x90,0x79,0x47,0x05,0xC2,0xFB,0x75,0xFF,0x00,0x3F,0xE6,0x8F,0xF3,0xFE,0x7F,0xCD,0x3F,0xF3,0xFE,0x7F,0xCD,0x54,0x70,0x1B,0x04,0xF5,0xEC,0x7A,0x7F,0x9F,0xF3,0x4C,0x0F,0x92,0x44,0x83,0x6B,0x0E,0xE7,0xFC,0xFF,0x00,0x9A,0xB4,0x51,0xB1,0xC1,0xDC,0xA4,0xF5,0x0B,0x9F,0xF3,0xFE,0x69,0xB3,0xC2,0xAC,0x9B,0xBC,0xB6,0xCA,0xFA,0x0F,0xF3,0xFE,0x69,0x7F,0x9F,0xF3,0xFE,0x69,0xFF,0x00,0x9F,0xF3,0xFE,0x6A,0x30,0xF2,0x26,0x01,0x8C,0x32,0x77,0x20,0xF0,0x7F,0xCF,0xF9,0xA8,0xE4,0x92,0x25,0x1B,0x57,0x72,0xA9,0xEA,0x08,0xE9,0xFE,0x7F,0xCD,0x5A,0xB7,0x41,0x2A,0xFC,0x85,0x91,0xBD,0x09,0xE3,0xFC,0xFF,0x00,0x9A,0x91,0xE3,0x56,0x05,0x2E,0x23,0xE0,0xFF,0x00,0x17,0x07,0x1F,0xE7,0xFC,0xD3,0xC7,0xF9,0xFF,0x00,0x3F,0xE6,0x96,0x7F,0xCF,0xF9,0xFF,0x00,0x35,0x9E,0xC8,0xC1,0x84,0x99,0xDC,0x17,0xD3,0xA8,0xFF,0x00,0x3F,0xE6,0x9E,0xAD,0xF3,0x6D,0x7C,0xF5,0xDE,0xB8,0xED,0xFE,0x7F,0xCD,0x21,0x84,0x5B,0xCB,0xC3,0x90,0xAA,0x71,0xF4,0xFF,0x00,0x3F,0xE6,0x9E,0x22,0x26,0x50,0xC4,0x80,0x3B,0x32,0xF6,0xFF,0x00,0x3F,0xE6,0x8F,0xF3,0xFE,0x7F,0xCD,0x1F,0xE7,0xFC,0xFF,0x00,0x9A,0xB8,0x84,0x89,0x95,0x9F,0xA3,0xAE,0xDF,0xF3,0xFE,0x69,0x57,0x7C,0x33,0xF9,0x64,0xFC,0xB2,0x64,0x8F,0x63,0x8E,0x9F,0xE7,0xFC,0xC6,0x52,0x4D,0x9E,0x5B,0x73,0xCE,0x51,0x87,0x4F,0xF3,0xFE,0x6A,0xC6,0x77,0xC7,0x1B,0x91,0xCA,0x8E,0x7F,0x97,0xF9,0xFF,0x00,0x35,0x5F,0xE7,0xFC,0xFF,0x00,0x9A,0x9F,0xF3,0xFE,0x7F,0xCD,0x47,0x8F,0xDD,0x1D,0xE4,0x82,0xC1,0x87,0xE7,0xFE,0x7F,0xCD,0x65,0x4E,0x30,0xC9,0x83,0x90,0x38,0xFD,0x7F,0xCF,0xF9,0xAD,0x8B,0x85,0xFD,0xD1,0x23,0xB7,0x23,0xFC,0xFF,0x00,0x9A,0xCA,0x50,0x0B,0x90,0x3B,0x80,0xDF,0x8F,0xF9,0xFF,0x00,0x35,0x24,0xFF,0x00,0x9F,0xF3,0xFE,0x6A,0x80,0xFF,0x00,0x3F,0xE7,0xFC,0xD4,0x8A,0xBF,0x2A,0xA0,0xCE,0x49,0xC9,0xFC,0x3F,0xCF,0xF9,0xAD,0x6B,0x72,0x5D,0x59,0x3A,0x1C,0x0F,0xF3,0xFE,0x7F,0xCE,0x5C,0x7F,0xEB,0x14,0x63,0xA2,0xF3,0xF5,0xFF,0x00,0x3F,0xE6,0xB4,0xE2,0x42,0x91,0x80,0xB9,0x1B,0xB8,0xCF,0xF9,0xFF,0x00,0x34,0x03,0xFE,0x7F,0xCF,0xF9,0xA0,0x8F,0xF3,0xFE,0x7F,0xCD,0x30,0xC6,0x36,0x65,0x09,0x53,0xEF,0xFE,0x7F,0xCD,0x47,0x13,0x48,0x83,0x2F,0x23,0xE3,0xD8,0x7F,0x9F,0xF3,0x4B,0xE5,0x71,0xB9,0x73,0x9F,0xF6,0x8F,0xF9,0xFF,0x00,0x35,0x22,0xA1,0x20,0x12,0x13,0xFC,0xFF,0x00,0x9F,0xF3,0x4B,0x3F,0xE7,0xFC,0xFF,0x00,0x9A,0x3F,0xCF,0xF9,0xFF,0x00,0x34,0xD2,0xCB,0x9C,0xE1,0xC7,0x1D,0x49,0xFF,0x00,0x3F,0xE6,0x9A,0x21,0xDC,0xE1,0x92,0x27,0x39,0xEA,0x58,0x67,0xFC,0xFF,0x00,0x9A,0xB2,0x15,0x78,0xF9,0x03,0x7F,0x9F,0xF3,0xFE,0x69,0x55,0x57,0xAE,0x14,0x7D,0x32,0x7F,0xCF,0xF9,0xA6,0x07,0xF9,0xFF,0x00,0x3F,0xE6,0x8C,0xFF,0x00,0x9F,0xF3,0xFE,0x69,0xD1,0xAA,0x01,0x86,0x00,0x37,0xB8,0xFF,0x00,0x3F,0xE6,0xA1,0xBA,0x11,0xEC,0x2D,0xBC,0x0D,0xBF,0xDD,0x03,0xFC,0xFF,0x00,0x9A,0x97,0x07,0x77,0x12,0x00,0x3D,0x02,0x7F,0x9F,0xF3,0x48,0xF2,0x27,0xFC,0xF1,0x66,0xC7,0x72,0x3F,0xCF,0xF9,0xAA,0xFF,0x00,0x3F,0xE7,0xFC,0xD2,0xFF,0x00,0x3F,0xE7,0xFC,0xD6,0x72,0x24,0x64,0x6E,0x2E,0xD9,0x6E,0x9C,0x67,0xFC,0xFF,0x00,0x9A,0xB2,0x56,0x37,0x50,0xAE,0x19,0x81,0xEE,0x47,0xF8,0x7F,0x9A,0x90,0xDC,0xC7,0xB7,0x6B,0x16,0x53,0xE9,0x91,0xFE,0x7F,0xCD,0x44,0x45,0xB4,0xE3,0x0B,0xB0,0xE3,0xAE,0xDE,0x4F,0xE9,0xFE,0x68,0xFF,0x00,0x3F,0xE7,0xFC,0xD1,0xFE,0x7F,0xCF,0xF9,0xAA,0xD7,0x36,0x23,0x39,0x56,0xC0,0xE8,0x33,0xFE,0x3F,0xE6,0xA0,0x81,0x65,0x8E,0x42,0xB2,0xA9,0x04,0x77,0x03,0x86,0x1E,0xBF,0xE7,0xFC,0xE8,0x2C,0xC2,0x30,0x12,0x57,0x21,0x7A,0x2B,0x13,0xD7,0xFC,0xFF,0x00,0x9A,0x79,0x8B,0x70,0x3C,0x63,0x3D,0x0A,0xFF,0x00,0x9F,0xF3,0x48,0xFF,0x00,0x9F,0xF3,0xFE,0x68,0xFF,0x00,0x3F,0xE7,0xFC,0xD4,0x7B,0x88,0x40,0xE3,0x05,0x73,0xCF,0xD3,0xDB,0xFC,0xD4,0xA3,0x3F,0x36,0x06,0x41,0xE7,0xFC,0xFF,0x00,0x9A,0x62,0x85,0xDE,0x50,0xF1,0x8F,0xCB,0xEB,0xFE,0x7F,0xCC,0xAA,0x36,0x47,0x81,0xFF,0x00,0xEA,0xFF,0x00,0x3F,0xE6,0x9F,0xF9,0xFF,0x00,0x3F,0xE6,0x8F,0xF3,0xFE,0x7F,0xCD,0x41,0x29,0xDB,0x13,0x0E,0x7D,0xBF,0xCF,0xF9,0xAC,0x70,0xC0,0xE3,0x07,0xA1,0xC9,0xFA,0x7A,0x7F,0x3F,0xF3,0x5A,0xB7,0x07,0x11,0x9C,0xF5,0x18,0xFF,0x00,0x3F,0xE7,0xFC,0xE6,0xA2,0xA9,0x2D,0xB4,0x72,0x78,0x23,0xFC,0xFF,0x00,0x9A,0xCC,0xFF,0x00,0x9F,0xF3,0xFE,0x6A,0x87,0xF9,0xFF,0x00,0x3F,0xE6,0xAE,0xDA,0x61,0x86,0x4A,0xE7,0xFC,0xFF,0x00,0x9F,0xF3,0x5A,0xB1,0xF3,0xC9,0x1D,0x07,0xF9,0xFF,0x00,0x3F,0xE6,0xAA,0x5A,0x44,0x17,0x18,0x1D,0x46,0x4F,0xF9,0xFF,0x00,0x35,0x7D,0x17,0x6A,0xFF,0x00,0x9F,0xF3,0xFE,0x68,0x1F,0xE7,0xFC,0xFF,0x00,0x9A,0x0F,0xF9,0xFF,0x00,0x3F,0xE6,0xB0,0xE2,0x70,0xCD,0xBD,0xD1,0x81,0x3D,0xFF,0x00,0xCF,0xF9,0xAB,0x61,0xA2,0x07,0x2D,0x9F,0xF8,0x11,0xFF,0x00,0x3F,0xE6,0xA5,0x10,0x20,0x03,0x00,0x01,0x8E,0x7F,0xCF,0xF9,0xA4,0xFB,0x1A,0x06,0xE9,0xC9,0xE8,0x47,0xF9,0xFF,0x00,0x34,0x1F,0xF3,0xFE,0x7F,0xCD,0x1C,0x7F,0x9F,0xF3,0xFE,0x6A,0x41,0x2A,0x04,0xDC,0xAC,0x00,0xF5,0xC7,0xF9,0xFF,0x00,0x35,0x04,0xDA,0xAD,0xB5,0xBE,0x72,0x4B,0xB7,0xD3,0xFC,0xFF,0x00,0x9A,0x25,0xB7,0xC0,0xC0,0x27,0xF1,0xFF,0x00,0x3F,0xE6,0xB0,0x35,0x30,0xA8,0x4F,0xB7,0xF9,0xFF,0x00,0x3F,0xE6,0xAD,0x79,0xFF,0x00,0x3F,0xE7,0xFC,0xD2,0x38,0x1F,0xE7,0xFC,0xFF,0x00,0x9A,0xB9,0x73,0xE2,0x1D,0xB9,0x11,0x20,0x39,0xF5,0xFF,0x00,0x3F,0xE6,0xAA,0xA6,0xAD,0x79,0x23,0x67,0x67,0x1F,0xE7,0xFC,0xFF,0x00,0x9A,0xAF,0x61,0x67,0xE6,0x9F,0x31,0xC6,0x73,0xD0,0x7F,0x9F,0xF3,0x5A,0xCB,0x6E,0xAA,0xB8,0x0B,0xFE,0x7F,0xCF,0xF9,0xA1,0x88,0x1C,0x7F,0x9F,0xF3,0xFE,0x6A,0x79,0x3C,0xFF,0x00,0x9F,0xF3,0xFE,0x6A,0x9B,0xDF,0x5E,0x11,0xCE,0xC1,0xEB,0xF2,0xF5,0xFF,0x00,0x3F,0xE6,0xA3,0x17,0xF7,0x4B,0xD5,0x94,0x8F,0xF7,0x71,0xFE,0x7F,0xCD,0x5E,0x30,0xA1,0x07,0x27,0x1F,0xE7,0xFC,0xFF,0x00,0x9A,0xA7,0x3C,0x20,0x02,0x43,0x0F,0x6E,0x79,0x3F,0xE7,0xFC,0xD0,0x39,0xFF,0x00,0x3F,0xE7,0xFC,0xD4,0x96,0xC7,0xF9,0xFF,0x00,0x3F,0xE6,0x9E,0x9A,0xB4,0xA9,0xC4,0xA9,0xBC,0x7B,0x9C,0xFF,0x00,0x3F,0xF3,0x53,0xC3,0xAD,0x45,0x9C,0x33,0x14,0xF5,0x56,0xE9,0xFE,0x7F,0xCD,0x60,0x49,0xE7,0xA3,0xE5,0xD5,0x82,0xFD,0x3F,0xCF,0xF9,0xA7,0x0C,0x30,0xE7,0x90,0x7F,0xCF,0xF9,0xFF,0x00,0x35,0x65,0x31,0xD7,0xFC,0xFF,0x00,0x9F,0xF3,0x48,0x49,0xFE,0x7F,0xCF,0xF9,0xAE,0xBE,0x29,0x22,0x97,0x0E,0x84,0x73,0xDC,0x7F,0x9F,0xF3,0x56,0x40,0x39,0xE0,0xF6,0xFF,0x00,0x3F,0xE7,0xFC,0xD7,0x1F,0x6D,0x3C,0xB6,0x6D,0x95,0x25,0xA3,0xEA,0x57,0x3D,0x3E,0x9F,0xE6,0xBA,0x3B,0x2B,0xE4,0xB9,0x8F,0x72,0xB6,0x7D,0x7D,0x7F,0xCF,0xF9,0xA9,0x23,0x1F,0xE7,0xFC,0xFF,0x00,0x9A,0xD0,0x1C,0xFF,0x00,0x9F,0xF3,0xFE,0x69,0xD7,0x4B,0xB9,0x09,0xFF,0x00,0x3F,0xE7,0xFC,0xD6,0x7C,0x28,0xC9,0x3B,0x9F,0xC7,0xFC,0xFF,0x00,0x9A,0xD3,0x97,0x91,0x91,0xFE,0x7F,0xCF,0xF9,0xA8,0xA3,0x80,0x6F,0x7D,0xDD,0x3B,0x7F,0x9F,0xF3,0x59,0x9C,0xFF,0x00,0x9F,0xF3,0xFE,0x6A,0xC7,0xF9,0xFF,0x00,0x3F,0xE6,0xAD,0x5B,0x1F,0x97,0x3F,0xE7,0xFC,0xFF,0x00,0x9A,0x9C,0xC8,0x71,0xEC,0x3F,0xCF,0xF9,0xFF,0x00,0x35,0x12,0x7C,0x8B,0x85,0xFF,0x00,0x3F,0xE7,0xFC,0xD2,0x7D,0xE6,0x03,0xB7,0x53,0xFE,0x7F,0xCD,0x30,0x3F,0xCF,0xF9,0xFF,0x00,0x34,0x8F,0xF9,0xFF,0x00,0x3F,0xE6,0x9D,0x6A,0x14,0x20,0xE7,0x20,0x8E,0x33,0xFE,0x7F,0xCD,0x4C,0x98,0x20,0x8C,0x71,0xDB,0xFC,0xFF,0x00,0x9A,0xA5,0x0E,0x63,0x53,0x9C,0x85,0x3F,0xA7,0xD3,0xFC,0xD5,0xA8,0xD8,0x37,0x19,0xC1,0xF5,0xFF,0x00,0x3F,0xE6,0x98,0xFF,0x00,0x3F,0xE7,0xFC,0xD2,0xFF,0x00,0x3F,0xE7,0xFC,0xD1,0x28,0xC8,0xFF,0x00,0x3F,0xE7,0xFC,0xD7,0x27,0xAB,0x1D,0xF7,0xA5,0x07,0x4C,0xFF,0x00,0x9F,0xF3,0xFE,0x6B,0xB0,0x75,0xE3,0x3F,0xAF,0xF9,0xFF,0x00,0x35,0xC8,0xEA,0x89,0xB7,0x52,0xCF,0x66,0x39,0xFF,0x00,0x3F,0xE6,0xA9,0x7A,0xFF,0x00,0x9F,0xF3,0xFE,0x69,0x37,0x4F,0xF3,0xFE,0x7F,0xCD,0x6B,0x59,0x44,0x91,0xC2,0xB8,0xFF,0x00,0x3F,0xE7,0xFC,0xD4,0xCE,0x06,0x38,0xFF,0x00,0x3F,0xE7,0xFC,0xD3,0x2D,0x80,0x68,0x17,0x1F,0xE7,0xFC,0xFF,0x00,0x9A,0x1C,0x15,0x3D,0x73,0xFE,0x7F,0xCF,0xF9,0xAC,0x7B,0xFF,0x00,0x9F,0xF3,0xFE,0x69,0x1F,0xF3,0xFE,0x7F,0xCD,0x38,0x46,0x3C,0xB2,0x48,0xFF,0x00,0x3F,0xE7,0xFC,0xD6,0x15,0xCD,0xEC,0x11,0x4B,0x75,0x13,0xC6,0x59,0x98,0x05,0x56,0x1F,0xC3,0x83,0xFE,0x7F,0xCD,0x6C,0xCD,0x38,0x86,0xDC,0xB3,0x72,0x47,0x38,0xFF,0x00,0x3F,0xE6,0xB9,0x0B,0x89,0x7C,0xE9,0xDE,0x4C,0x63,0x71,0xCF,0xF9,0xFF,0x00,0x35,0xD7,0x17,0x1F,0xE7,0xFC,0xFF,0x00,0x9A,0xC5,0xCF,0xF9,0xFF,0x00,0x3F,0xE6,0xAE,0xCC,0x65,0x58,0x87,0xCE,0x59,0x0F,0x63,0xFE,0x7F,0xCD,0x32,0xDD,0x77,0x8C,0x77,0x1F,0xE7,0xFC,0xFF,0x00,0x9A,0x6C,0x52,0xEE,0xB3,0x91,0x5D,0xB2,0x41,0x18,0xCF,0xF9,0xFF,0x00,0x35,0x36,0x9E,0x32,0x58,0xFF,0x00,0x9F,0xF3,0xFE,0x6A,0x9B,0xA7,0xF9,0xFF,0x00,0x3F,0xE6,0x97,0x7F,0xF3,0xFE,0x7F,0xCD,0x4A,0xB1,0xF6,0x3F,0xE7,0xFC,0xFF,0x00,0x9A,0x8D,0x66,0x6B,0x0B,0x90,0xEA,0x4E,0xC6,0xEA,0x3F,0xCF,0xF9,0xAD,0x05,0x8C,0x16,0xFF,0x00,0x3F,0xE7,0xFC,0xD5,0x3D,0x52,0x3C,0x27,0x03,0xA7,0xF9,0xFF,0x00,0x3F,0xE6,0xB9,0xC1,0xF9,0xB1,0xFE,0x7F,0xCF,0xF9,0xAD,0x7B,0x67,0xFC,0xFF,0x00,0x9F,0xF3,0x5B,0xD6,0x97,0x0B,0x3C,0x79,0x53,0xD7,0xFC,0xFF,0x00,0x9F,0xF3,0x56,0xD3,0xEE,0x1F,0x5C,0x7F,0x9F,0xF3,0xFE,0x6B,0x98,0xD0,0xE7,0x61,0x28,0x8F,0x3C,0x76,0xFF,0x00,0x3F,0xE6,0xBA,0x78,0xBE,0xE8,0xFF,0x00,0x3F,0xE7,0xFC,0xD5,0x63,0x07,0x1F,0xE7,0xFC,0xFF,0x00,0x9A,0xB0,0x72,0x33,0xFE,0x7F,0xCF,0xF9,0xA7,0xE0,0x80,0x7F,0xCF,0xF9,0xFF,0x00,0x34,0xC3,0x90,0x46,0x3B,0xFF,0x00,0x2F,0xF3,0xFE,0x6A,0x4F,0xE1,0x1E,0xE7,0xFC,0xFF,0x00,0x9F,0xF3,0x4C,0xC9,0xC9,0x6C,0x67,0xFC,0xFF,0x00,0x9F,0xF3,0x52,0x47,0xF9,0xFF,0x00,0x3F,0xE6,0x9F,0xF9,0xFF,0x00,0x3F,0xE6,0xA9,0xC7,0x2B,0x80,0x57,0x19,0x5F,0xD4,0x7F,0x9F,0xF3,0x56,0x63,0x94,0x22,0x0C,0x83,0x81,0xE9,0xD4,0x7F,0x9F,0xF3,0x54,0x92,0x65,0x75,0xE9,0x8E,0x71,0x91,0xDB,0xFC,0xFF,0x00,0x9A,0x3C,0xD7,0x89,0xC7,0x1C,0x7F,0x31,0xFE,0x7F,0xCD,0x40,0xFF,0x00,0x3F,0xE7,0xFC,0xD3,0xFF,0x00,0x3F,0xE7,0xFC,0xD6,0xCA,0x30,0x64,0xCE,0x72,0x0F,0xF9,0xFF,0x00,0x3F,0xE6,0xB9,0xFF,0x00,0x10,0x5B,0x72,0xB3,0xA0,0xE9,0xD4,0xFF,0x00,0x9F,0xF3,0x5A,0x96,0xB7,0x01,0xC1,0x0A,0xC3,0x23,0xF8,0x4F,0xF9,0xFF,0x00,0x35,0x2D,0xCC,0x2B,0x3C,0x25,0x4E,0x3F,0xCF,0xF9,0xFF,0x00,0x35,0x79,0xC7,0x3F,0xE7,0xFC,0xFF,0x00,0x9A,0x9C,0x67,0xFC,0xFF,0x00,0x9F,0xF3,0x59,0x3A,0x5C,0x86,0x58,0x00,0xCF,0x23,0xFC,0xFF,0x00,0x9F,0xF3,0x56,0x1C,0x60,0xE3,0x23,0xFC,0xFF,0x00,0x9F,0xF3,0x58,0xF1,0x33,0x58,0x5E,0x18,0x5F,0x21,0x73,0xC7,0xF9,0xFF,0x00,0x35,0xB0,0xAB,0xE7,0x20,0x60,0x79,0xFF,0x00,0x3F,0xE7,0xFC,0xD4,0x30,0xC1,0xFF,0x00,0x3F,0xE7,0xFC,0xD4,0xFF,0x00,0x9F,0xF3,0xFE,0x6A,0x95,0xC8,0x2C,0xAC,0x31,0xD4,0x7F,0x9F,0xF3,0xFE,0x6B,0x98,0x75,0xD9,0x23,0x29,0xEC,0x71,0xFE,0x7F,0xCD,0x75,0xD2,0xC5,0x81,0xC9,0x3F,0xE7,0xFC,0xFF,0x00,0x9A,0xC0,0xD4,0x2C,0x98,0xCF,0xBA,0x31,0x90,0x7A,0xFF,0x00,0x9F,0xF3,0x5A,0xC4,0xC3,0xA7,0xF9,0xFF,0x00,0x3F,0xE6,0xB2,0x65,0x3F,0xE7,0xFC,0xFF,0x00,0x9A,0xA3,0xB8,0x31,0x01,0x57,0x1F,0xD7,0xFC,0xFF,0x00,0x9A,0xD7,0xB4,0x5D,0x91,0x85,0x0A,0x37,0x75,0x3F,0xE7,0xFC,0xD4,0x16,0xB6,0x81,0x3E,0x63,0xCB,0x7F,0x2F,0xF3,0xFE,0x6B,0x4A,0x08,0x73,0xD3,0xFC,0xFF,0x00,0x9F,0xF3,0x54,0xEE,0x3F,0xCF,0xF9,0xFF,0x00,0x34,0x2A,0xFF,0x00,0x9F,0xF3,0xFE,0x6A,0x58,0x94,0x9E,0xDD,0x7F,0xCF,0xF9,0xFF,0x00,0x35,0x4B,0x56,0xF9,0x63,0x2B,0xFE,0x7F,0xCF,0xF9,0xAD,0x6D,0x82,0x18,0xC9,0xCF,0x4F,0xF3,0xFE,0x7F,0xCD,0x64,0xBE,0x2E,0xEE,0x70,0xC7,0xE4,0x1C,0x93,0xFE,0x7F,0xCD,0x64,0x9F,0x33,0x7F,0x9F,0xF3,0xFE,0x6B,0x5E,0x83,0xFC,0xFF,0x00,0x9F,0xF3,0x59,0xF6,0x4C,0x63,0x9D,0x1B,0x38,0xE7,0xFC,0xFF,0x00,0x9F,0xF3,0x5D,0x95,0xB1,0x0E,0x8B,0x93,0x9F,0xF3,0xFE,0x7F,0xCD,0x71,0xCD,0x85,0x9C,0xED,0xE9,0x9E,0x3F,0xCF,0xF9,0xAE,0xAB,0x4B,0x93,0x75,0xBA,0x9F,0x4E,0xE7,0xFC,0xFF,0x00,0x9A,0xD5,0xBA,0xFF,0x00,0x9F,0xF3,0xFE,0x68,0x5E,0x9F,0xE7,0xFC,0xFF,0x00,0x9A,0xBF,0x8F,0x97,0xF4,0xFF,0x00,0x3F,0xE6,0x9A,0x47,0x18,0xE9,0x9E,0xBF,0xE7,0xFC,0xD4,0xB8,0x01,0x76,0x8E,0xDD,0xCF,0xF9,0xFF,0x00,0x34,0x8E,0xB9,0x04,0xE7,0x81,0xD4,0xFF,0x00,0x9F,0xF3,0x52,0x7F,0xCF,0xF9,0xFF,0x00,0x35,0x43,0xFC,0xFF,0x00,0x9F,0xF3,0x58,0x7B,0x76,0x7C,0xD9,0x01,0xB3,0xCF,0xF9,0xFF,0x00,0x34,0x48,0x8E,0xF0,0xEE,0x5D,0xCB,0x83,0xC8,0xEB,0xF9,0x7F,0x9A,0x95,0x90,0x13,0xCA,0xF5,0x18,0x04,0x74,0x3F,0xE7,0xFC,0xD2,0x26,0x23,0xF9,0x43,0x1C,0x77,0x1D,0x76,0xFE,0x1E,0x9F,0xE6,0xB3,0xFF,0x00,0x3F,0xE7,0xFC,0xD5,0x7F,0x9F,0xF3,0xFE,0x6A,0x14,0xDE,0x8C,0xA7,0x9D,0xB9,0xED,0xDB,0xDF,0xE9,0xFE,0x6B,0x4E,0xDE,0xE7,0x73,0x6D,0x24,0x1F,0x7F,0xF3,0xFE,0x6A,0x98,0x47,0x43,0x90,0xCB,0xB4,0x9E,0x55,0x8F,0x1F,0x81,0xFF,0x00,0x35,0x5E,0x64,0x2B,0x26,0xEC,0x32,0x2E,0x7A,0x7F,0x81,0xFF,0x00,0x34,0x7F,0x9F,0xF3,0xFE,0x68,0xFF,0x00,0x3F,0xE7,0xFC,0xD6,0x86,0xA7,0xA6,0x25,0xDC,0x7B,0x81,0xDA,0xC3,0xA1,0x1F,0xE7,0xFC,0xD6,0x55,0xB5,0xCC,0x96,0x92,0x79,0x57,0x20,0xA9,0xE8,0x1B,0xD7,0xFC,0xFF,0x00,0x9A,0xD4,0xB6,0xBC,0x75,0x50,0x24,0x1B,0x90,0xF4,0x6E,0x87,0xF1,0xFF,0x00,0x35,0x34,0xF6,0xD0,0xDD,0xC2,0xC0,0x85,0x6F,0xE9,0xFE,0x7F,0xCD,0x1E,0xDF,0xE7,0xFC,0xFF,0x00,0x9A,0x92,0x3F,0xCF,0xF9,0xFF,0x00,0x35,0x0A,0xBA,0x4A,0xB9,0x24,0x1C,0xFF,0x00,0x9F,0xF3,0xFE,0x6A,0xBC,0xB6,0x6A,0xE4,0xF3,0x9F,0xF3,0xFE,0x7F,0xCD,0x53,0x7B,0x1B,0xDB,0x32,0x5A,0x02,0x59,0x07,0x63,0xFE,0x7F,0xCD,0x44,0x35,0x7B,0x88,0x8E,0xD9,0x61,0xE4,0x7B,0x7F,0x9F,0xF3,0x53,0xB0,0xF6,0xFF,0x00,0x3F,0xE7,0xFC,0xD4,0x9E,0x3A,0xFF,0x00,0x9F,0xF3,0xFE,0x6B,0x45,0x2C,0x02,0x8C,0xB7,0xF9,0xFF,0x00,0x3F,0xE6,0xA7,0xF2,0xA3,0x89,0x0B,0x1E,0x00,0xFF,0x00,0x3F,0xE7,0xFC,0xD6,0x23,0xEB,0x2E,0x4E,0xE5,0x5C,0x1F,0x73,0xFE,0x7F,0xCD,0x55,0xB8,0xBF,0xB8,0xB8,0xFB,0xCC,0x71,0xE8,0x3F,0xCF,0xF9,0xAB,0x11,0xB1,0xEB,0xFE,0x7F,0xCF,0xF9,0xA9,0xC8,0xFF,0x00,0x3F,0xE7,0xFC,0xD5,0xED,0x42,0xFB,0xCD,0x3E,0x5C,0x3D,0x3D,0x7F,0xCF,0xF9,0xAA,0xCE,0xC2,0x0B,0x72,0x37,0x7E,0xF1,0xBB,0x7F,0x5F,0xF3,0xFE,0x6A,0xC7,0x2B,0xA1,0xCA,0xA8,0x27,0xDF,0xFC,0xFF,0x00,0x9A,0x47,0x59,0x24,0x72,0xCD,0xC9,0x3F,0xE7,0xFC,0xFF,0x00,0x9A,0xD9,0x40,0x51,0xC7,0xF9,0xFF,0x00,0x3F,0xE6,0x8E,0x4F,0xF9,0xFF,0x00,0x3F,0xE6,0x98,0x3E,0xF8,0xFF,0x00,0x3F,0xE7,0xFC,0xD7,0x47,0xA2,0x31,0xD8,0x41,0xE8,0x3F,0xCF,0xF9,0xFF,0x00,0x35,0xCF,0x2A,0x10,0xE3,0x23,0xFC,0xFF,0x00,0x9F,0xF3,0x5B,0x7A,0x43,0x95,0x7C,0x74,0xCF,0xF9,0xFF,0x00,0x3F,0xE6,0x93,0x7F,0x9F,0xF3,0xFE,0x6A,0x97,0xFC,0xFF,0x00,0x9F,0xF3,0x5D,0x20,0xC6,0x00,0xED,0xD4,0xFF,0x00,0x9F,0xF3,0x4E,0x3B,0x4A,0x70,0x30,0xBF,0xE7,0xFC,0xFF,0x00,0x9A,0x89,0x5C,0x3E,0x00,0xE4,0xF6,0x1D,0xBF,0xCF,0xF9,0xA9,0x71,0xC7,0x5E,0x7F,0xCF,0xF9,0xFF,0x00,0x35,0x27,0xA7,0xF9,0xFF,0x00,0x3F,0xE6,0xA8,0x7F,0x9F,0xF3,0xFE,0x6B,0x27,0x0B,0x90,0xCB,0x8E,0xBD,0xBA,0x7F,0x9F,0xF3,0x51,0x4A,0x86,0x52,0xCE,0x99,0x56,0x07,0x93,0xFE,0x7F,0xCD,0x32,0x09,0x41,0x52,0x48,0x60,0x08,0xE7,0x03,0x3F,0xE7,0xFC,0xD5,0x84,0x52,0x47,0x0C,0x02,0x9E,0x8D,0xD4,0x1F,0xAF,0xF9,0xA8,0xFF,0x00,0x3F,0xE7,0xFC,0xD5,0x7F,0x9F,0xF3,0xFE,0x6A,0x1D,0x8C,0xAB,0xF3,0xF0,0x7B,0x83,0xD0,0xFF,0x00,0x9F,0xF3,0x4D,0xF2,0xD4,0xC6,0x36,0x1D,0xC8,0x4F,0x4E,0xDF,0x97,0x6F,0xF3,0x53,0xC9,0xE6,0x05,0xDA,0xAA,0xA4,0x1F,0x7F,0xE5,0xFE,0x6A,0x30,0x52,0x06,0xCB,0x02,0xA4,0x7E,0xBF,0x97,0xF9,0xA3,0xFC,0xFF,0x00,0x9F,0xF3,0x4B,0xFC,0xFF,0x00,0x9F,0xF3,0x4A,0xAE,0xBB,0x48,0x60,0xD8,0xE8,0x46,0x7F,0xCF,0xF9,0xA7,0xAB,0xBC,0x6A,0x1E,0x33,0x95,0xEF,0xFE,0x7F,0xCD,0x2B,0xF9,0x6D,0xF3,0x82,0x01,0x3D,0x46,0x3A,0xFF,0x00,0x9F,0xF3,0x51,0x88,0xE4,0x07,0x23,0x0E,0xBD,0x78,0x3C,0x8F,0xF3,0xFE,0x69,0x7F,0x9F,0xF3,0xFE,0x68,0xFF,0x00,0x3F,0xE7,0xFC,0xD6,0x84,0x33,0xAC,0xC8,0x37,0x60,0x1F,0x71,0xFE,0x7F,0xCD,0x32,0x6B,0x08,0xA5,0x5F,0xB8,0xA7,0xFC,0xFF,0x00,0x9F,0xF3,0x54,0x84,0x8C,0x49,0xC8,0xC1,0x1D,0x88,0xE7,0xFC,0xFF,0x00,0x9A,0xB1,0x6F,0x70,0xC0,0x74,0x63,0x83,0x8C,0x11,0x8F,0xF3,0xFE,0x6A,0x7A,0x7F,0x9F,0xF3,0xFE,0x69,0xFF,0x00,0x9F,0xF3,0xFE,0x6A,0xAC,0x9A,0x1C,0x5D,0x76,0x81,0xFE,0x7F,0xCF,0xF9,0xA6,0xB6,0x86,0x8B,0xD0,0x7F,0x9F,0xF3,0xFE,0x6B,0x61,0x67,0xC8,0xE5,0x40,0xF7,0xFF,0x00,0x3F,0xE6,0x9D,0xE6,0x29,0xF4,0x3F,0xE7,0xFC,0xFF,0x00,0x9A,0xA0,0x4F,0xAF,0xF9,0xFF,0x00,0x3F,0xE6,0x8C,0x7F,0x9F,0xF3,0xFE,0x6B,0x1D,0x74,0xB8,0x90,0xFC,0xC0,0x1F,0x6F,0xF3,0xFE,0x6A,0x8D,0xE5,0xBA,0x47,0x90,0xA3,0xF0,0xFF,0x00,0x3F,0xE6,0xB6,0xAE,0x24,0xC1,0x3B,0x48,0x27,0xE9,0xFE,0x7F,0xCD,0x64,0xDC,0x65,0xDC,0xE4,0x31,0xCF,0xF9,0xFF,0x00,0x3F,0xE6,0x8C,0xF3,0xFE,0x7F,0xCF,0xF9,0xAA,0x03,0xFC,0xFF,0x00,0x9F,0xF3,0x59,0xBB,0x71,0x19,0x3D,0xFF,0x00,0xCF,0xF9,0xFF,0x00,0x35,0x6B,0x4F,0x93,0xF7,0x9F,0x78,0xFE,0x1F,0xE7,0xFC,0xD2,0xCD,0x18,0x48,0xFD,0x4F,0xF9,0xFF,0x00,0x3F,0xE6,0xA0,0xB5,0xFD,0xDC,0x9C,0xAF,0x5E,0x7F,0xCF,0xF9,0xAB,0x2D,0x91,0xFE,0x7F,0xCF,0xF9,0xA8,0x03,0x07,0xFC,0xFF,0x00,0x9F,0xF3,0x5D,0x65,0xBB,0x7C,0xA1,0x79,0x27,0x1F,0xE7,0xFC,0xFF,0x00,0x9A,0x9D,0x88,0x54,0xE0,0xFF,0x00,0x9F,0xF3,0xFE,0x6A,0x85,0xA4,0xE1,0x63,0x05,0x7B,0xFA,0xF2,0x7F,0xCF,0xF9,0xA9,0x8C,0xCB,0x27,0xCA,0xC7,0x1F,0xE7,0xFC,0xFF,0x00,0x9A,0x8D,0xDF,0xE7,0xFC,0xFF,0x00,0x9A,0x78,0xFF,0x00,0x3F,0xE7,0xFC,0xD6,0x16,0x08,0x6D,0xEA,0x48,0x3F,0xE7,0xFC,0xFF,0x00,0x9A,0x94,0x5D,0x48,0xBE,0x8D,0xEC,0x7A,0x9F,0xF3,0xFE,0x69,0x91,0xC4,0xC9,0xCE,0x41,0x1F,0xE7,0xFC,0xFF,0x00,0x9A,0xB0,0x62,0x47,0x51,0x95,0xC7,0xF9,0xFF,0x00,0x3F,0xE6,0x83,0xFE,0x7F,0xCF,0xF9,0xA7,0xFE,0x7F,0xCF,0xF9,0xA6,0xC5,0x2A,0xCC,0xD9,0x52,0x63,0xC7,0xF0,0xE7,0xFC,0xFF,0x00,0x9A,0xB2,0x77,0x32,0x11,0xF2,0x96,0x3C,0x8C,0x8C,0x7F,0x9F,0xF3,0x55,0xDA,0xD6,0x32,0x33,0xCB,0x01,0xE8,0x7F,0xCF,0xF9,0xA7,0x24,0x68,0x88,0x0A,0x96,0x51,0xF5,0x38,0xFC,0xFF,0x00,0xCD,0x1F,0xE7,0xFC,0xFF,0x00,0x9A,0x5F,0xE7,0xFC,0xFF,0x00,0x9A,0x7C,0x42,0x26,0x1E,0x5B,0x38,0x12,0xE3,0x90,0x4F,0x4F,0xCF,0xFC,0xD4,0x6C,0x88,0xB2,0xE0,0xB1,0x0C,0x3A,0xE4,0xF3,0xF8,0x7F,0x9A,0x52,0x8B,0x9D,0xEA,0xE0,0x30,0xE9,0x8F,0xF3,0xFE,0x69,0xCF,0x3A,0x14,0xCB,0x8C,0xBF,0xA6,0x31,0xFE,0x7F,0xCD,0x3F,0xF3,0xFE,0x7F,0xCD,0x2F,0xF3,0xFE,0x7F,0xCD,0x48,0x19,0x31,0xF3,0x38,0x3E,0x9B,0xF3,0xFE,0x7F,0xCD,0x27,0x94,0xAC,0xB9,0x46,0x00,0x8E,0xEA,0xD9,0x03,0xFC,0xFF,0x00,0x9A,0x8C,0xAB,0x05,0x32,0x22,0x06,0x53,0xE8,0xD8,0xFC,0xC7,0xF9,0xA9,0x4C,0x69,0xB1,0x4A,0xBB,0x21,0x23,0x9C,0x7F,0x87,0xF9,0xA5,0xFE,0x7F,0xCF,0xF9,0xA3,0xFC,0xFF,0x00,0x9F,0xF3,0x4D,0x25,0xA3,0x61,0xBD,0xC1,0x07,0x8C,0xF3,0x9F,0xF3,0xFE,0x69,0xEA,0xE0,0x7F,0x12,0xFD,0x01,0x1F,0xE7,0xFC,0xD0,0x99,0x18,0x4F,0x37,0x77,0xFD,0x73,0x03,0xF5,0x1F,0xE6,0x96,0x48,0x55,0x57,0x2C,0x4B,0x1F,0xF6,0xBF,0xCF,0xF9,0xA9,0xC7,0xF9,0xFF,0x00,0x3F,0xE6,0x9E,0x7F,0xCF,0xF9,0xFF,0x00,0x34,0xC3,0x87,0xFE,0x3D,0xC4,0x76,0x1F,0xE7,0xFC,0xD5,0x77,0x4E,0xFB,0x4E,0x3A,0x73,0xFE,0x7F,0xCD,0x4E,0xB0,0xE5,0x79,0x76,0xFA,0x1E,0x07,0xE5,0xDF,0xFC,0xD3,0x25,0x5C,0x90,0x06,0x4F,0x38,0xF7,0xFF,0x00,0x3F,0xE6,0x8F,0xF3,0xFE,0x7F,0xCD,0x50,0x3F,0xE7,0xFC,0xFF,0x00,0x9A,0xA5,0x22,0x82,0x3E,0x63,0xC6,0x7F,0xCF,0xF9,0xFF,0x00,0x35,0x5D,0xCE,0x3E,0x62,0x46,0x7A,0x0F,0xF3,0xFE,0x6A,0xE4,0xD0,0xB0,0x04,0x93,0xC0,0xE9,0x9F,0xF3,0xFE,0x6A,0xAC,0xE0,0x33,0xE3,0xF8,0x71,0x9F,0xF3,0xFE,0x69,0x8F,0xF3,0xFE,0x7F,0xCD,0x1F,0xE7,0xFC,0xFF,0x00,0x9A,0x9E,0xD6,0x77,0x20,0x2A,0xE7,0xEB,0xFE,0x7F,0xCD,0x68,0xC6,0xCA,0x19,0x47,0xF7,0x7B,0x9F,0xF3,0xFE,0x6B,0x36,0xDC,0x15,0x03,0x68,0xE3,0xAF,0xD3,0xFC,0xFF,0x00,0x9A,0xBD,0x18,0xC3,0xE4,0x9E,0x0F,0x3D,0x3F,0xCF,0xF9,0xA9,0x27,0x9F,0xF3,0xFE,0x7F,0xCD,0x3C,0x7F,0x9F,0xF3,0xFE,0x6B,0xFF,0xD9,};

    
    long long unsigned int len =  4404;
    long long unsigned int coded_len;
    unsigned char* coded_bin = b64_encode(jpeg_bin, len, &coded_len);
    printf("%d, %s", len, coded_bin);
}


static const unsigned char base64_table[65] =
	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char *b64_encode(const unsigned char *in, size_t len, size_t *out_len)
{
	char   *out;
	size_t  elen;
	size_t  i;
	size_t  j;
	size_t  v;

	if (in == NULL || len == 0)
		return NULL;

	elen = b64_encoded_size(len);
	out  = malloc(elen+1);
	out[elen] = '\0';

	for (i=0, j=0; i<len; i+=3, j+=4) {
		v = in[i];
		v = i+1 < len ? v << 8 | in[i+1] : v << 8;
		v = i+2 < len ? v << 8 | in[i+2] : v << 8;

		out[j]   = base64_table[(v >> 18) & 0x3F];
		out[j+1] = base64_table[(v >> 12) & 0x3F];
		if (i+1 < len) {
			out[j+2] = base64_table[(v >> 6) & 0x3F];
		} else {
			out[j+2] = '=';
		}
		if (i+2 < len) {
			out[j+3] = base64_table[v & 0x3F];
		} else {
			out[j+3] = '=';
		}
	}

    *out_len =  b64_encoded_size(len);

	return out;
}

size_t b64_encoded_size(size_t inlen)
{
	size_t ret;

	ret = inlen;
	if (inlen % 3 != 0)
		ret += 3 - (inlen % 3);
	ret /= 3;
	ret *= 4;

	return ret;
}