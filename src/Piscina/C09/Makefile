EX01=ex01
EX02=ex02

all: ${EX01} ${EX02}

${EX01}:
	$(MAKE) -C ${EX01}

${EX02}:
	$(MAKE) -C ${EX02}

clean:
	$(MAKE) clean -C ${EX01}
	$(MAKE) clean -C ${EX02}

fclean: 
	$(MAKE) fclean -C ${EX01}
	$(MAKE) fclean -C ${EX02}

re:
	$(MAKE) re -C ${EX01}
	$(MAKE) re -C ${EX02}

.PHONY: all clean fclean re ${EX01} ${EX02}
