void switch_hw5(long a, long b, long c, long *dest)
{
    long val;
    switch(a) {
        case 0:
            val = c - a;
            break;
        case 1:
            // c = (b << 4) + b -> b*2^4 + b -> 16 * b + b -> 17 * b
            c = 17 * b;
            /* Fall through */
        case 3:
            val = c ^ 0xFF;
            break;
        case 5:
        case 7:
            val = (b + c) >> 4;
            break;
        default:
            val = a + b;
    }
    return val;
}

/*
(b) Assembly Code
switch_hw5:
.L3:
	movq	%rdx, %rax
	subq	%rdi, %rax
	ret
.L5: no ret so a = 1
	movq	%rsi, %rdx
	salq	$4, %rdx
	addq	%rsi, %rdx
.L6:
	movq	%rdx, %rax
	xorb	$-1, %al
	ret
.L7:
	leaq	(%rdx,%rsi), %rax
	sarq	$4, %rax
	ret
.L2:
	leaq	(%rdi,%rsi), %rax
	ret
(c) Jump Table
.L4:
    .quad	.L3     a = 0
    .quad	.L5     a = 1
    .quad	.L2     a = 2
    .quad	.L6     a = 3
    .quad	.L2     a = 4
    .quad	.L7     a = 5
    .quad	.L2     a = 6
    .quad	.L7     a = 7
*/