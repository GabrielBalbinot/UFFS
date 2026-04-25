# busca binária
.data
	str: .string "Target: "
	target_found: .string "Valor encontrado na posição: "
	target_not_found: .string "Valor não encontrado!\n"
	arr: .word -97, -83, -61, -42, -17, 8, 25, 49, 73, 91
	arr_size: .word 10
.text
.globl main

main:
	# leitura de target
	la a0 str
	li a7 4
	ecall
	li a7 5
	ecall
	add a1 a0 zero # a1 = target
	
	# load do array e size
	la s0 arr # s0 = ponteiro pro início do array
	la s1 arr_size
	lw s1 0(s1) # s1 = size
	
	li t0 0 # left
	add t1 s1 zero # right
	li t6 2 # divisor de middle
	
	li a0 0 # flag para target found	
	
	while:
		bgt t0 t1 end_while
		# middle
		sub t2 t1 t0
		srli t2 t2 1 
		add t2 t2 t0
		
		# load de arr[middle]
		slli t3 t2 2
		add t3 t3 s0
		lw t3 0(t3)
		
		beq t3 a1 found
		bgt t3 a1 greater
		addi t0 t2 1
		j while		
		greater:
		addi t1 t2 -1
		j while
		
		found:
		addi a0 zero 1
	end_while:
	li a7 4
	
	beq a0 zero not_found
	la a0 target_found
	ecall
	li a7 1
	add a0 t2 zero
	ecall
	j end_program
	
	not_found:
		la a0 target_not_found
		ecall	
	end_program:
		li a7 10
		ecall
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	