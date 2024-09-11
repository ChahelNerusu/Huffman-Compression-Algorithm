#include "bitwriter.h"

#include <stdio.h>
#include <stdlib.h>

struct BitWriter {
    FILE *underlying_stream;
    uint8_t byte;
    uint8_t bit_position;
};

BitWriter *bit_write_open(const char *filename) {
    BitWriter *writer = (BitWriter *) malloc(sizeof(BitWriter));
    FILE *f = fopen(filename, "wb");
    writer->underlying_stream = f;
    writer->byte = 0;
    writer->bit_position = 0;
    return writer;
}
void bit_write_close(BitWriter **pbuf) {
    if (*pbuf != NULL) {
        if ((*pbuf)->bit_position > 0) {
            if (fputc((*pbuf)->byte, (*pbuf)->underlying_stream) == EOF) {
                fprintf(stderr, "Fatal error\n");
                exit(1);
            }
        }

        if (fclose((*pbuf)->underlying_stream) != 0) {
            fprintf(stderr, "Fatal error\n");
            exit(1);
        }

        free(*pbuf);
        *pbuf = NULL;
    }
}
void bit_write_bit(BitWriter *buf, uint8_t bit) {
    if (buf->bit_position > 7) {
        if (fputc(buf->byte, buf->underlying_stream) == EOF) {
            perror("Error writing");
            exit(1);
        }
        buf->byte = 0;
        buf->bit_position = 0;
    }
    buf->byte |= (bit & 1) << buf->bit_position;
    buf->bit_position += 1;
}

void bit_write_uint8(BitWriter *buf, uint8_t x) {
    for (int i = 0; i < 8; i++) {
        bit_write_bit(buf, (x >> i) & 1);
    }
}
void bit_write_uint32(BitWriter *buf, uint32_t x) {
    for (int i = 0; i < 32; i++) {
        bit_write_bit(buf, (uint8_t) ((x >> i) & 1));
    }
}
void bit_write_uint16(BitWriter *buf, uint16_t x) {
    for (int i = 0; i < 16; i++) {
        bit_write_bit(buf, (uint8_t) ((x >> i) & 1));
    }
}
