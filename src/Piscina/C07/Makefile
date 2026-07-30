EX00=ex00
EX01=ex01
EX02=ex02
EX03=ex03
EX04=ex04
EX05=ex05

all: ${EX00} ${EX01} ${EX02} ${EX03} ${EX04} ${EX05}

#Con Make - C se ejecuta el make en la carpeta que le pasemos por parámetro
${EX00}:
	$(MAKE) -C ${EX00}

${EX01}:
	$(MAKE) -C ${EX01}

${EX02}:
	$(MAKE) -C ${EX02}

${EX03}:
	$(MAKE) -C ${EX03}

${EX04}:
	$(MAKE) -C ${EX04}

${EX05}:
	$(MAKE) -C ${EX05}

clean:
	$(MAKE) clean -C ${EX00}
	$(MAKE) clean -C ${EX01}
	$(MAKE) clean -C ${EX02}
	$(MAKE) clean -C ${EX03}
	$(MAKE) clean -C ${EX04}
	$(MAKE) clean -C ${EX05}

fclean: 
	$(MAKE) fclean -C ${EX00}
	$(MAKE) fclean -C ${EX01}
	$(MAKE) fclean -C ${EX02}
	$(MAKE) fclean -C ${EX03}
	$(MAKE) fclean -C ${EX04}
	$(MAKE) fclean -C ${EX05}
re:
	$(MAKE) re -C ${EX00}
	$(MAKE) re -C ${EX01}
	$(MAKE) re -C ${EX02}
	$(MAKE) re -C ${EX03}
	$(MAKE) re -C ${EX04}
	$(MAKE) re -C ${EX05}

.PHONY: all clean fclean re ${EX00} ${EX01} ${EX02} ${EX03} ${EX04} ${EX05}