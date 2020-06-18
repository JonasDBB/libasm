; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strlen.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: jbennink <jbennink@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/10 14:18:57 by jbennink      #+#    #+#                  ;
;    Updated: 2020/06/17 16:13:26 by jbennink      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

	global	_ft_strlen
	
	section .text
_ft_strlen:
	xor		rax, rax

_loop:
	cmp		[rdi + rax], byte 0
	je		_end
	inc		rax
	jmp		_loop

_end:
	ret