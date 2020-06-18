; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strcpy.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: jbennink <jbennink@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/10 16:35:21 by jbennink      #+#    #+#                  ;
;    Updated: 2020/06/17 14:08:36 by jbennink      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

	global	_ft_strcpy

	section .text
_ft_strcpy:
	xor		rax, rax

_loop:
	cmp		[rsi + rax], byte 0
	je		_end
	mov		rcx, [rsi + rax]
	mov		[rdi + rax], rcx
	inc		rax
	jmp		_loop

_end:
	mov		rax, rdi
	ret