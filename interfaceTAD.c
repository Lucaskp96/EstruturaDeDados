/*-- Funções triviais de uma TAD --*/
void RESET(TAD* ed);
bool EMPTY(TAD* ed);
bool FULL(TAD* ed);
bool PUSH(TAD* ed, Dado* dado);
void POP(TAD* ed, Dado* dado);
void CLEAR(TAD* ed);
void PRINT(TAD* ed);
void showMenu(void);

/*-- Interface --*/
void showMenu(){
    do{
		setbuf(stdin,NULL);
		printf(": ");
		scanf("%c", op);
		getchar();
		switch(*op){
			case '1':
					RESET(estrutura);
					if(EMPTY) printf(" Estrutura iniciada!\n");
				break;
			case '2':
					printf("Digite os dados do novo elemento\n");
					printf(" Nome: ");
					setbuf(stdin,NULL);
					fgets(pessoa->name,32,stdin);
					enterRemove(pessoa->name);
					printf(" Idade: ");
					scanf("%d", &pessoa->idade);
					PUSH(estrutura, pessoa);
				break;
			case '3':
					POP(estrutura, pessoa);
				break;
			case '4':
					CLEAR(estrutura);
				break;
			case '5':
					PRINT(estrutura);
				break;
			case '6':
					printf(" Saindo...\n");
				break;
			default:
					printf(" Opção inválida\n");
		}
	}while(*op != '6');
}
