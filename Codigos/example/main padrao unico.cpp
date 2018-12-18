#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <termios.h>
#include <time.h>
#include <dlp.h>
#include <iostream>

using namespace std;
 
int main() {
	DLP *teste = new DLP();
	bool err = teste->openDLP();
	if (!err) printf("erro na funcao de abertura\n");
	int reg = 0x80;
	int showErro = 1;
	__s32 res;
	char buf[15];
	string operacao;
	while (operacao != "0"){
		cout << "Digite a opcao desejada: " << endl;
		cout << "1 - Escolher teste de padrão;" << endl;
		cout << "2 - Teste rotatório de imagens;" << endl;
		cout << "3 - Escolher entrada HDMI;" << endl;
		cout << "4 - Escolher entrada FPD-Link;" << endl;
		cout << "5 - Mostrar imagem da flash;" << endl;
		cout << "6 - Testar padrao 3D;" << endl;
		cout << "10 - Mostrar/Esconder mensagens de erro;" << endl;
		cout << "0 - Para sair do programa. " << endl;
		
		getline(cin, operacao);
		cout <<  endl;

		if (operacao == "1"){
			cout << "Digite um numero entre 1 e 11. " << endl;
			getline(cin, operacao);
			cout <<  endl;
			buf[0] = 0x80;
			buf[1] = 0x11; 
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita.\n");
			}

			buf[0] = 0x8a;
			buf[1] = std::stoi(operacao);
			buf[1]--;
			
			usleep(100);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita.2\n");
			}
		} else if (operacao == "2"){
			buf[0] = 0x80;
			buf[1] = 0x11; 
			
			usleep(100);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita.\n");
				//printf(" \"i2c.write()\" done. status = %d", status);
			}
			buf[0] = 0x8a;
			buf[1] = 0x00;
			buf[3] = 0;
			
			usleep(100);
			while (buf[3] < 5){
				usleep(1000000);
				while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
					usleep(100);
					if (showErro) printf("Erro de escrita.2\n");
				}
				if (buf[1] == 11){
					buf[1] = 0x00;
					buf[3]++;
				} else {
					buf[1]++;
				}
			}
		} else if (operacao == "3"){
			buf[0] = 0x80;
			buf[1] = 0x00;
			
			usleep(100); 
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita.\n");
			}
		} else if (operacao == "4"){
			buf[0] = 0x80;
			buf[1] = 0x03; 
		
			
			usleep(100);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita.\n");
			}
		} else if (operacao == "5"){
			buf[0] = 0x80;
			buf[1] = 0x02; 
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita.\n");
			}
		} else if (operacao == "6"){
			buf[0] = 0xe9; // Set Display 
			buf[1] = 0x01; // pattern mode
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Nao foi possivel setar o display como teste.\n");
			}

		
			buf[0] = 0xef; // Pattern Display
			buf[1] = 0x03; // From Flash
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Nao foi possivel escolher padrao da flash.\n");
			}

			buf[0] = 0xf5; // PDVE Control
			buf[1] = 0x01; //  
			buf[2] = 0x01; // 
			buf[3] = 0x00; // 
			buf[4] = 0x01; // always repeat 
		
			while (write(teste->kI2CFileDescriptor, buf, 5) < 1){
				usleep(100);
				if (showErro) printf("Erro de aplicar trigger interno.\n");
			}

			buf[0] = 0xf0; // PDVE Control
			buf[1] = 0x01; //  
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de abertura do mailbox.\n");
			}


			buf[0] = 0xe6; // PDVE Control

			buf[1] = 0x05; //  
			buf[2] = 0x00; // 
			buf[3] = 0x03; // 
			buf[4] = 0x00; // 

			buf[5] = 0x04; //  
			buf[6] = 0x00; // 
			buf[7] = 0x00; // 
			buf[8] = 0x10; // 
 
		
			while (write(teste->kI2CFileDescriptor, buf, 9) < 1){
				usleep(100);
				if (showErro) printf("Erro de controle do PDVE.\n");
			}

			buf[0] = 0xf7; // 
			buf[1] = 0x01; // 
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de fechamento do mailbox.\n");
			}


			buf[0] = 0xf6; // Offset Pointer
			buf[1] = 0x00; // inicializacao em 0
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de reset do pointer de offet.\n");
			}

			buf[0] = 0xf8; // Pattern Data
			buf[1] = 0x00; // image Index
			buf[2] = 0x01; // 
			//buf[3] = 0x00; // 
			//buf[4] = 0x01; // 
		
			while (write(teste->kI2CFileDescriptor, buf, 3) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita do dado de padrao.\n");
			}

			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x00; // Close Mailbox
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de fechamento do mailbox.\n");
			}

			// STEP 7

			buf[0] = 0xf7; // Data Validate
			buf[1] = 0x02; // Valida o PDVE
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de validacao.\n");
			}


			buf[0] = 0xf6; // 
			buf[1] = 0x00; // 
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de validacao.\n");
			}


			buf[0] = 0xf8; // 
			buf[1] = 0x00; // 
			buf[2] = 0x24; // 
			buf[3] = 0x06; // 
		
			while (write(teste->kI2CFileDescriptor, buf, 4) < 1){
				usleep(100);
				if (showErro) printf("Erro de validacao.\n");
			}


			buf[0] = 0xf6; // 
			buf[1] = 0x01; // 
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de validacao.\n");
			}


			buf[0] = 0xf8; // 
			buf[1] = 0x04; // 
			buf[2] = 0x44; // 
			buf[3] = 0x06; // 
		
			while (write(teste->kI2CFileDescriptor, buf, 4) < 1){
				usleep(100);
				if (showErro) printf("Erro de validacao.\n");
			}

			// read?

			buf[0] = 0xfd; // 
			buf[1] = 0x00; // 

		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de validacao.\n");
			}
			int x;
			buf[0] = 0xfd;
			x = (int) read(teste->kI2CFileDescriptor, buf, 1);
			printf("primeira leitura = %d\n", x);

			x = (int) read(teste->kI2CFileDescriptor, buf, 1);
			printf("segunda leitura = %d\n", x);

			/*buf[1] = read(teste->kI2CFileDescriptor, buf, 1);
			x = atoi(buf[1]);
			printf("segunda leitura = %d\n", x);*/

						

			buf[0] = 0xe5; // PDVE status
			buf[1] = 0x02; // Start
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de inicio do padrao.\n");
			}


			while (operacao != "s") {
				printf( "Digite s para parar.\n");
				getline(cin, operacao);
			}

			buf[0] = 0xe5; // PDVE status
			buf[1] = 0x00; // Stop
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de parada do padrao.\n");
			}


			buf[0] = 0xe9; // Set Display 
			buf[1] = 0x00; // video mode
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Nao foi possivel setar o display como video.\n");
			}

		} else if (operacao == "10") {
			if (showErro){
				showErro = 0;
				printf("Mensagens de erros desativadas.\n");
			} else {
				showErro = 1;
				printf("Mensagens de erros ativadas.\n"); 
			}

		}
	cout << "Teste concluido, retornando ao menu inicial..." << endl << endl;
	}
	teste->closeDLP();
}

