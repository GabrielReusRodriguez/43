# Raíz de src/Piscina — construye todos los módulos C/Rush disponibles
MODULES=C00 C01 C02 C03 C04 C05 C06 C07 C08 C09 C10 C11 C12 C13

all:
	@for m in $(MODULES); do \
		echo "==== $$m ===="; \
		$(MAKE) -C $$m all || exit 1; \
	done
	@$(MAKE) -C Rush00/ex00 all

clean:
	@for m in $(MODULES); do \
		$(MAKE) -C $$m clean || true; \
	done
	@$(MAKE) -C Rush00/ex00 clean || true

fclean:
	@for m in $(MODULES); do \
		$(MAKE) -C $$m fclean || true; \
	done
	@$(MAKE) -C Rush00/ex00 fclean || true

re: fclean all

test:
	@../../tests/Piscina/run_tests.sh

.PHONY: all clean fclean re test
