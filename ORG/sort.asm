.data
	nums:      .word 9 3 14 1 12 5 15 2 11 4 8 13 6 10 7 9 3 14 1 12 5 15 2 11 4 8 13 6 10 7
    nums_size: .word 30

.text
.globl main

main:
    la   s0, nums
    la   a0, nums_size
    lw   a2, 0(a0)
    li   a1, 0          # low = 0
    addi a2, a2, -1     # high = size-1
    jal  ra, quicksort

    li   a7, 10
    ecall

quicksort:
	
	# erro ao armazenar os valores na stack (low ta sendo o high anterior)
	
	# a1 low, a2 high
	add t0 a1 zero
	add t1 a2 zero
	
    bge  t0, t1, end_quick

    addi sp, sp, -12
    sw   ra, 8(sp) # valor de ra
	sw t0 4(sp) # low
	sw t1 0(sp) # high  
    
	add a1 t0 zero
	add a2 t1 zero
	jal partition
	add t2 a0 zero # pivot
	
	addi sp sp -4
	sw t2 0(sp) 
	
	# chama o quick na partição esquerda
	lw a1 8(sp)
	addi a2 t2 -1
	jal quicksort 
    
    # chama o quick na partição direita
    lw a1 0(sp)
    addi a1 a1 1
    lw a2 4(sp)
    jal quicksort
	
    lw   ra, 12(sp)
    addi sp, sp, 16

end_quick:
    jr ra    

partition:
	# s0 = arr, a1 = low, a2 = high
	
	add t0 a2 zero # high
	addi a0 a1 -1 # i
	add t1 a1 zero # j
	
	# offeset para pegar arr[pivotIndex]	
	slli t2 a2 2 
	add t2 t2 s0	
	addi sp sp -4
	sw t2 0(sp)	
	lw t2 0(t2) # t2 = arr[pivotIndex]
				
	while:
		bge t1 t0 end_while
		slli t3 t1 2 # offset para pegar arr[j]
		add t3 t3 s0
		lw t4 0(t3)	 # arr[j]
		
		# if (arr[j] < arr[pivotIndex]
		bgt t4 t2 next
		addi a0 a0 1
		
		# swap		
		slli t5 a0 2 # offset para pegar arr[i]
		add t5 t5 s0 # t5 é &arr[i]
		lw t6 0(t5) # t6 é arr[i] e agirá como temp
		sw t4 0(t5) # arr[i] = arr[j]
		sw t6 0(t3) # arr[j] = arr[i] (ou arr[j] = temp)		
			
		next:
		addi t1 t1 1 # j++
		j while	
	end_while:
	
	# swap
    
    addi a0 a0 1 # i++
    slli t5 a0 2 # offset para pegar arr[i+1]
	add t5 t5 s0 # t5 é &arr[i+1]
	lw t6 0(t5) # t6 é arr[i+1] e agirá como temp
	sw t2 0(t5) # arr[i+1] = arr[pivotIndex]
	lw t5 0(sp)
	sw t6 0(t5) # arr[pivotIndex] = arr[i+1] (ou arr[pivotIndex] = temp)
	
	addi sp sp 4
	
	jr ra   
