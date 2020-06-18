; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_read.s                                          :+:    :+:             ;
;                                                      +:+                     ;
;    By: jbennink <jbennink@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/10 16:37:25 by jbennink      #+#    #+#                  ;
;    Updated: 2020/06/16 15:31:45 by jbennink      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

	global	_ft_read
	extern	___error

	section	.text
_ft_read:
	mov		rax, 0x02000003
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