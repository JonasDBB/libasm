; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strcmp.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: jbennink <jbennink@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/10 16:35:32 by jbennink      #+#    #+#                  ;
;    Updated: 2020/06/17 14:08:13 by jbennink      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

	global	_ft_strcmp

	section	.text
_ft_strcmp:
	xor		rax, rax

_loop:
	cmp		[rdi + rax], byte 0
	je		_end2
	cmp		[rsi + rax], byte 0
	je		_end1
	mov		dl, [rsi + rax]
	cmp		[rdi + rax], dl
	jg		_end1
	jb		_end2
	inc		rax
	jmp		_loop

_end1:
	mov		rax, 1
	ret

_end2:
	cmp		[rsi + rax], byte 0
	je		_ret
	mov		rax, -1
	ret

_ret:
	mov		rax, 0
	ret
