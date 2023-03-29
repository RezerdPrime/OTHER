system 0
mov 0, r0

; --- x1 * 100 ---
mov 1, r1 ; <---
;out r1, p1
shl 6, r1
or r1, r0

shr 1, r1
add r1, r0

shr 3, r1
or r1, r0

; --- x2 * 10 ---
mov 2, r1 ; <---
;out r1, p2
shl 3, r1
or r1, r0
 
shr 2, r1
add r1, r0

; --- x3 * 1 ---
mov 3, r1 ; <---
;out r1, p3
or r1, r0

;out r0, p0
stop

