; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strdup.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: jbennink <jbennink@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/10 16:37:40 by jbennink      #+#    #+#                  ;
;    Updated: 2020/06/17 14:47:40 by jbennink      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

	global	_ft_strdup
	extern	_malloc
	extern	_ft_strlen
	extern	_ft_strcpy

	section	.text
_ft_strdup:
	push	rdi
	call	_ft_strlen
	mov		rcx, rax
	mov		rdi, rcx
	call	_malloc
	pop		rsi
	cmp		rax, 0
	je		_end
	mov		rdi, rax
	push	rdi
	call	_ft_strcpy
	pop		rdi
	ret

_end:
	ret