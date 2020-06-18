; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_write.s                                         :+:    :+:             ;
;                                                      +:+                     ;
;    By: jbennink <jbennink@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/10 16:37:08 by jbennink      #+#    #+#                  ;
;    Updated: 2020/06/16 15:32:22 by jbennink      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

	global	_ft_write
	extern	___error

	section	.text
_ft_write:
	mov		rax, 0x02000004
	syscall
	jc		_err
	ret

_err:
	push	rax
	call	___error
	pop		rcx
	mov		[rax], rcx
	mov		rax, -1
	ret