#include "ft_printf.h"
#include <stdio.h>

// int main(void)
// {
//     int n1, n2;

//     // Title for test cases
//     printf("Testing all flag combinations for integers:\n\n");

//     // Array of test values to check for different cases
//     int test_values[] = {42, -42, 0, 2147483647, -2147483648};
//     const char *formats[] = {
//         "{%d}",           // Basic
//         "{%+d}",          // Plus
//         "{% d}",          // Space
//         "{%-d}",          // Left-align
//         "{%#x}",          // Alternate form (hex)
//         "{%010d}",        // Zero-padded
//         "{%+010d}",       // Plus and zero-padding
//         "{%-+10d}",       // Plus, left-aligned
//         "{%#.10x}",       // Alternate with precision
//         "{%-#10x}",       // Alternate, left-aligned
//         "{%+10.5d}",      // Plus with width and precision
//         "{%-+10.5d}",     // Plus, left-aligned with precision
//         "{%0+10.5d}",     // Zero-padded with plus and precision
//         "{%#010x}"        // Zero-padded alternate hex
//     };

//     // Loop through each format and test value
//     for (int i = 0; i < sizeof(formats) / sizeof(formats[0]); i++) {
//         printf("Format: %s\n", formats[i]);

//         for (int j = 0; j < sizeof(test_values) / sizeof(test_values[0]); j++) {
//             n1 = ft_printf("|copy : ");
//             n1 += ft_printf(formats[i], test_values[j]);
//             n1 += ft_printf("|\n");

//             printf("n1 = %d\n", n1);

//             n2 = printf("|orig : ");
//             n2 += printf(formats[i], test_values[j]);
//             n2 += printf("|\n");

//             printf("n2 = %d\n\n", n2);
//         }
//     }

//     return 0;
// }
// int main()
// {
//     int n1 = ft_printf("copy is : |%12.d|\n", 0);
//     int n2 =    printf("orig is : |%12.d|\n", 0);
//     printf("nC = %d , nO = %d", n1, n2);
// }