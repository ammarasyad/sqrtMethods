public asmSqrt
.code
asmSqrt PROC
    vsqrtpd ymm0, ymm0
    ret
asmSqrt ENDP

END