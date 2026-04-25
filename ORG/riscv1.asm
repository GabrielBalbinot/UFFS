.data
	str: .string "N: "
	achou: .string "Valor encontrado na posição: "
	nachou: .string "Valor não encontrado!\n"
	arr: .word 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
	arr_size: .word 10
.text
.globl main
	
main:
	
	#
	lui a0 %hi(str)
	addi a0 a0 %lo(str)
	
	# print N:
	li a7 4
	ecall
	# Leitura de N (target):
	li a7 5
	ecall
	
	add a6 zero a0 # target
	
	# load do array e tamanho
	lui a1 %hi(arr)
	addi a1 a1 %lo(arr)
	la a2 arr_size
	lw a2 0(a2)
	
	# busca do valor
	add t0 zero zero # i
	add t1 zero zero # flag para busca (0 = não achou e 1 = achou)
	
	for:
		beq t0 a2 endfor
		slli t2 t0 2 # offset de 4 a partir de i
		add t2 t2 a1 # pega o endereço de arr[i]
		lw t3 0(t2) # carrega o valor de arr[i]
		addi t0 t0 1		
		bne t3 a6 for
		addi t1 t1 1	
	endfor:
	
	li a7 4
	
	beq t1 zero n_achou
	
	# valor encontrado
	la a0 achou
	ecall
	li a7 1
	add a0 zero t0
	ecall
	j fim
	
	n_achou:
	la a0 nachou
	ecall	
	fim:
	
	li a7 10
	ecall
	
	
	
	
	
	
	
	
	
	
	
	
	
	