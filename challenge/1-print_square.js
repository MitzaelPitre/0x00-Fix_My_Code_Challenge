#!/usr/bin/node

if (process.argv.length <= 2) {
    process.stderr.write("Missing argument\n");
    process.stderr.write("Usage: ./1-print_square.js <size>\n");
    process.stderr.write("Example: ./1-print_square.js 8\n");
    process.exit(1);
}

const size = parseInt(process.argv[2], 10);

if (isNaN(size) || size <= 0) {
    process.stderr.write("Size must be a positive integer\n");
    process.exit(1);
}

for (let i = 0; i < size; i++) {
    console.log("#".repeat(size));
}
