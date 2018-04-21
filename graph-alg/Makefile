Message_heur = "Done building heuristics driver"
Message_plain = "Done building regular driver"

all: regular heuristic
	cat README

regular: graph-driver.c connected-components.c
	clang graph-driver.c connected-components.c -o graph-driver
	@echo $(Message_heur)

heuristic: heuristic-driver.c heuristic.c 
	clang heuristic-driver.c heuristic.c -o heuristic-driver
	@echo $(Message_plain)
