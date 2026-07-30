EX00=ex00
EX01=ex01
EX02=ex02

all: ${EX00} ${EX01} ${EX02}

#Con Make - C se ejecuta el make en la carpeta que le pasemos por parámetro
${EX00}:
	$(MAKE) -C ${EX00}

${EX01}:
	$(MAKE) -C ${EX01}

${EX02}:
	$(MAKE) -C ${EX02}

clean:
	$(MAKE) clean -C ${EX00}
	$(MAKE) clean -C ${EX01}
	$(MAKE) clean -C ${EX02}

fclean: 
	$(MAKE) fclean -C ${EX00}
	$(MAKE) fclean -C ${EX01}
	$(MAKE) fclean -C ${EX02}
re:
	$(MAKE) re -C ${EX00}
	$(MAKE) re -C ${EX01}
	$(MAKE) re -C ${EX02}

.PHONY: all clean fclean re ${EX00} ${EX01} ${EX02}