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
	string operacao;
	if (!err) {
		printf("Erro na funcao de abertura\n");
		printf("Verifique seu driver de comunicação i2c e reinicie o programa.\n");
		operacao = "0";
	}
	int reg = 0x80;
	int showErro = 0;
	int wt;
	__s32 res;
	char buf[15];
	while (operacao != "0"){
		cout << "Digite a opcao desejada: " << endl;
		cout << "1 - Escolher teste de padrão;" << endl;
		cout << "2 - Teste rotatório de imagens;" << endl;
		cout << "3 - Escolher entrada HDMI;" << endl;
		cout << "4 - Escolher entrada FPD-Link;" << endl;
		cout << "5 - Mostrar imagem da flash;" << endl;
		cout << "6 - Testar padrao 3D (60 Hz);" << endl;
		cout << "7 - Testar padrao 3D (120 Hz)" << endl;
		// cout << "8 - Teste de Variable Exposure (3D)" << endl;
		// cout << "9 - Teste de Pattern Sequence (3D)" << endl;
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
			
			int i = 0;
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				i = write(teste->kI2CFileDescriptor, buf, 2);				
				usleep(100);
				if (showErro) printf("Erro de escrita. %d\n", i);
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
			

			printf("Digite o numero de interações.\n");
			getline(cin, operacao);
			wt = std::stoi(operacao);
			usleep(100);
			while (buf[3] < wt){
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
			buf[0] = 0x84;
			buf[1] = 0x80; 
		
			
			usleep(1000);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita.\n");
			}

			buf[0] = 0x85;
			buf[1] = 0x00; 
		
			
			usleep(1000);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita.\n");
			}


			buf[0] = 0x82;
			buf[1] = 0x00; 
		
			
			usleep(1000);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita.\n");
			}

			buf[0] = 0x80;
			buf[1] = 0x0b; 
		
			
			usleep(1000);
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
		} else if (operacao == "9"){
			buf[0] = 0xe9; // Set Display 
			buf[1] = 0x01; // pattern mode
usleep(100000);		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Nao foi possivel setar o display como teste.\n");
			}

		
			buf[0] = 0xef; // Pattern Display
			buf[1] = 0x03; // From Flash
usleep(100000);		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Nao foi possivel escolher padrao da flash.\n");
			}

			buf[0] = 0xf0; // Trigger
			buf[1] = 0x03; // for Variable Exposure
usleep(100000);		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de aplicar trigger interno.\n");
			}

			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x03; // Open Mailbox for Variable Exposure
usleep(100000);		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de abertura do mailbox.\n");
			}


			buf[0] = 0xdb; // PDVE Control
			buf[1] = 0x03; // exposure pattern
			buf[2] = 0x00; // 
			buf[3] = 0x01; // trigger out
			buf[4] = 0x00; // 
			buf[5] = 0x03; // images
			buf[6] = 0x01; // always repeat 
 
usleep(100000);		
			while (write(teste->kI2CFileDescriptor, buf, 7) < 1){
				usleep(100);
				if (showErro) printf("Erro de controle do PDVE.\n");
			}
usleep(100000);
			buf[0] = 0xdc; // LUT Offset
			buf[1] = 0x00; // inicio: 0
			buf[2] = 0x00;
usleep(100000);
			while (write(teste->kI2CFileDescriptor, buf, 3) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita da LUT de offset.\n");
			}

			buf[0] = 0xdd; // LUT Data
			buf[1] = 0x00; // trigger in + index
			buf[2] = 0x78; // bit-depth + LED green on
			buf[3] = 0x04; // trigger out + no black-fill
			buf[4] = 0x00; // 
			buf[5] = 0x8d; // exposicao por imagem = 16 667 us = (0x411b)
			buf[6] = 0x20; // 
			buf[7] = 0x00; // 
			buf[8] = 0x00; //  
			buf[9] = 0x8d; // periodo = 833 350 us = 0.833 s = (CB746)
			buf[10] = 0x20; // 
			buf[11] = 0x00; // 
			buf[12] = 0x00; // images

		
usleep(100000);
			while (write(teste->kI2CFileDescriptor, buf, 13) < 1){
				usleep(1000);
				if (showErro) printf("Erro de escrita do PDVE.\n");
			}
usleep(100000);
			buf[0] = 0xdc; // LUT Offset
			buf[1] = 0x01; // +1
			buf[2] = 0x00;

			while (write(teste->kI2CFileDescriptor, buf, 3) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita da LUT de offet.\n");
			}

			buf[0] = 0xdd; // LUT Data
			buf[1] = 0x00; // trigger in + index 
			buf[2] = 0x78; // bit-depth + LED red on
			buf[3] = 0x04; // trigger out + no black-fill
			buf[4] = 0x00; // 
			buf[5] = 0x8d; // images
			buf[6] = 0x20; // always repeat
			buf[7] = 0x00; //  
			buf[8] = 0x00; // 
			buf[9] = 0x8d; // 
			buf[10] = 0x20; // 
			buf[11] = 0x00; // images
			buf[12] = 0x00; // 
			
usleep(100000);			
			while (write(teste->kI2CFileDescriptor, buf, 13) < 1){
				usleep(1000);
				if (showErro) printf("Erro de escrita do PDVE 2.\n");
			}

			
usleep(100000);
			buf[0] = 0xdc; // LUT Offset
			buf[1] = 0x02; // +2
			buf[2] = 0x00;

			while (write(teste->kI2CFileDescriptor, buf, 3) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita da LUT de offset.\n");
			}

			buf[0] = 0xdd; // LUT Data
			buf[1] = 0x00; // trigger in + index
			buf[2] = 0x78; // bit-depth + LED green on
			buf[3] = 0x04; // trigger out + no black-fill
			buf[4] = 0x00; // 
			buf[5] = 0x8d; // exposicao por imagem = 16 667 us = (0x411b)
			buf[6] = 0x20; // 
			buf[7] = 0x00; // 
			buf[8] = 0x00; //  
			buf[9] = 0x8d; // periodo = 833 350 us = 0.833 s = (CB746)
			buf[10] = 0x20; // 
			buf[11] = 0x00; // 
			buf[12] = 0x00; // images

		
usleep(100000);
			while (write(teste->kI2CFileDescriptor, buf, 13) < 1){
				usleep(1000);
				if (showErro) printf("Erro de escrita do PDVE.\n");
			}

			
usleep(100000);
			buf[0] = 0xdc; // LUT Offset
			buf[1] = 0x03; // +3
			buf[2] = 0x00;

			while (write(teste->kI2CFileDescriptor, buf, 3) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita da LUT de offset.\n");
			}

			buf[0] = 0xdd; // LUT Data
			buf[1] = 0x00; // trigger in + index
			buf[2] = 0x78; // bit-depth + LED green on
			buf[3] = 0x04; // trigger out + no black-fill
			buf[4] = 0x00; // 
			buf[5] = 0x8d; // exposicao por imagem = 16 667 us = (0x411b)
			buf[6] = 0x20; // 
			buf[7] = 0x00; // 
			buf[8] = 0x00; //  
			buf[9] = 0x8d; // periodo = 833 350 us = 0.833 s = (CB746)
			buf[10] = 0x20; // 
			buf[11] = 0x00; // 
			buf[12] = 0x00; // images

		
usleep(100000);
			while (write(teste->kI2CFileDescriptor, buf, 13) < 1){
				usleep(1000);
				if (showErro) printf("Erro de escrita do PDVE.\n");
			}


			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x00; // Close Mailbox
usleep(100000);		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de fechamento do mailbox.\n");

			}

			buf[0] = 0xdc; // LUT Offset
			buf[1] = 0x00; // Reset
			buf[2] = 0x00; 
usleep(100000);		
			while (write(teste->kI2CFileDescriptor, buf, 3) < 1){
				usleep(100);
				if (showErro) printf("Erro de reset da LUT de offet.\n");
			}

			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x01; // Image Index Mailbox
usleep(100000);		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de abertura do mailbox.\n");
			}

			buf[0] = 0xf6; // Offset Pointer
			buf[1] = 0x00; // inicializacao em 0
	usleep(100000);	
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de reset do pointer de offet.\n");
			}

			buf[0] = 0xf8; // Pattern Data
			buf[1] = 0x2; // image Index
			buf[2] = 0x1; // 
			buf[3] = 0x1; //  
			buf[4] = 0x1; //
	usleep(100000);	
			while (write(teste->kI2CFileDescriptor, buf, 5) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita do dado de padrao.\n");
			}


			/*buf[0] = 0xf6; // Offset Pointer
			buf[1] = 0x01; // +1
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de reset do pointer de offet.\n");
			}

			buf[0] = 0xf8; // Pattern Data
			buf[1] = 0x01; // image Index
			// buf[2] = 0x01; // 
			// buf[3] = 0x02; // 
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita do dado de padrao.\n");
			}*/


			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x00; // Close Mailbox
	usleep(100000);	
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de fechamento do mailbox.\n");
			}

			/*

			buf[1] = 0xe6; // 
			buf[2] = 0x10; // exposicao por imagem = 16 667 us = (0x411b)
			buf[3] = 0x27; // 
			buf[4] = 0x00; // 
			buf[5] = 0x10; //  
			buf[6] = 0x10; // periodo = 833 350 us = 0.833 s = (CB746)
			buf[7] = 0x27; // 
			buf[8] = 0x00; // 
			buf[9] = 0x10; // images

		
usleep(1000);
			while (write(teste->kI2CFileDescriptor, buf, 13) < 1){
				usleep(1000);
				if (showErro) printf("Erro de escrita do PDVE.\n");
			}
*/


usleep(100000);
			buf[0] = 0xfd; // Data Validate
			buf[1] = 0x00; // Valida o PDVE
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de validacao.\n");
			}

			// read?
			int x;
			buf[0] = 0xfd;
			x = (int) read(teste->kI2CFileDescriptor, buf, 1);
			// printf("primeira leitura = %d\n", x);
			usleep (100000);

			x = (int) read(teste->kI2CFileDescriptor, buf, 1);
			char ch = read(teste->kI2CFileDescriptor, buf, 1);
			// printf("segunda leitura = %d\n", x);
			cout << hex << (int) ch << endl;

			/*buf[1] = read(teste->kI2CFileDescriptor, buf, 1);
			x = atoi(buf[1]);
			printf("segunda leitura = %d\n", x);*/

						
usleep(100000);
			buf[0] = 0xe5; // PDVE status
			buf[1] = 0x02; // Start
while(operacao == "9") {	
printf( "iniciar?.\n");
getline(cin, operacao);
}			

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
	usleep(100000);	
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de parada do padrao.\n");
			}


			buf[0] = 0xe9; // Set Display 
			buf[1] = 0x00; // video mode
	usleep(100000);	
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Nao foi possivel setar o display como video.\n");
			}

		}  else if (operacao == "6"){
			buf[0] = 0xe9; // Set Display 
			buf[1] = 0x01; // pattern mode
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Nao foi possivel setar o display como teste.\n");
			}

usleep(100000);
			buf[0] = 0xef; // Pattern Display
			buf[1] = 0x03; // From Flash
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Nao foi possivel escolher padrao da flash.\n");
			}
usleep(100000);
			buf[0] = 0xf0; // Trigger
			buf[1] = 0x03; // for Variable Exposure
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de aplicar trigger interno.\n");
			}
usleep(100000);
			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x03; // Open Mailbox for Variable Exposure
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de abertura do mailbox.\n");
			}

usleep(100000);
			buf[0] = 0xdb; // PDVE Control
			buf[1] = 0x01; // 1+1 exposure pattern
			buf[2] = 0x00; // 
			buf[3] = 0x01; // 1+1 patterns to display
			buf[4] = 0x00; // 
			buf[5] = 0x01; // 1+1 images
			buf[6] = 0x01; // always repeat 
 
		
			while (write(teste->kI2CFileDescriptor, buf, 7) < 1){
				usleep(100);
				if (showErro) printf("Erro de controle do PDVE.\n");
			}
usleep(100000);
			buf[0] = 0xdc; // LUT Offset
			buf[1] = 0x00; // inicio: 0
			buf[2] = 0x00;

			while (write(teste->kI2CFileDescriptor, buf, 3) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita da LUT de offset.\n");
			}
usleep(100000);
			buf[0] = 0xdd; // LUT Data
			buf[1] = 0x00; // trigger in + index
			buf[2] = 0x48; // bit-depth + LED blue on 4
			buf[3] = 0x00; // trigger out + no black-fill
			buf[4] = 0x00; // 
			buf[5] = 0x1b; // exposicao por imagem = 16 667 us = (0x411b)
			buf[6] = 0x41; // 
			buf[7] = 0x00; // 
			buf[8] = 0x00; //  
			buf[9] = 0x1b; // periodo = 833 350 us = 0.833 s = (CB746)
			buf[10] = 0x41; // 
			buf[11] = 0x00; // 
			buf[12] = 0x00; // images

		

			while (write(teste->kI2CFileDescriptor, buf, 13) < 1){
				usleep(1000);
				if (showErro) printf("Erro de escrita do PDVE.\n");
			}
usleep(100000);
			buf[0] = 0xdc; // LUT Offset
			buf[1] = 0x01; // +1
			buf[2] = 0x00;

			while (write(teste->kI2CFileDescriptor, buf, 3) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita da LUT de offet.\n");
			}
usleep(100000);
			buf[0] = 0xdd; // LUT Data
			buf[1] = 0x00; // trigger in + index 
			buf[2] = 0x18; // bit-depth + LED red on
			buf[3] = 0x00; // trigger out + no black-fill
			buf[4] = 0x00; // 
			buf[5] = 0x1b; // images
			buf[6] = 0x41; // always repeat
			buf[7] = 0x00; //  
			buf[8] = 0x00; // 
			buf[9] = 0x1b; // 
			buf[10] = 0x41; // 
			buf[11] = 0x00; // images
			buf[12] = 0x00; // 
			
usleep(100000);			
			while (write(teste->kI2CFileDescriptor, buf, 13) < 1){
				usleep(1000);
				if (showErro) printf("Erro de escrita do PDVE 2.\n");
			}

			
usleep(100000);
			
			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x00; // Close Mailbox
	
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de fechamento do mailbox.\n");

			}

			buf[0] = 0xdc; // LUT Offset
			buf[1] = 0x00; // Reset
			buf[2] = 0x00; 
usleep(100000);		
			while (write(teste->kI2CFileDescriptor, buf, 3) < 1){
				usleep(100);
				if (showErro) printf("Erro de reset da LUT de offet.\n");
			}

			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x01; // Image Index Mailbox
usleep(100000);		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de abertura do mailbox.\n");
			}

			buf[0] = 0xf6; // Offset Pointer
			buf[1] = 0x00; // inicializacao em 0
usleep(100000);		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de reset do pointer de offet.\n");
			}
usleep(100000);
			buf[0] = 0xf8; // Pattern Data
			buf[1] = 0x00; // image Index
			buf[2] = 0x00; // 
			// buf[3] = 0x02; //  
		
			while (write(teste->kI2CFileDescriptor, buf, 3) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita do dado de padrao.\n");
			}/*

usleep(100000);
			buf[0] = 0xf6; // Offset Pointer
			buf[1] = 0x01; // +1
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de reset do pointer de offet.\n");
			}
usleep(100000);
			buf[0] = 0xf8; // Pattern Data
			buf[1] = 0x0; // image Index
			// buf[2] = 0x01; // 
			// buf[3] = 0x02; // 
		


			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita do dado de padrao.\n");
			}*/

usleep(100000);
			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x00; // Close Mailbox
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de fechamento do mailbox.\n");
			}

			/*

			buf[1] = 0xe6; // 
			buf[2] = 0x10; // exposicao por imagem = 16 667 us = (0x411b)
			buf[3] = 0x27; // 
			buf[4] = 0x00; // 
			buf[5] = 0x10; //  
			buf[6] = 0x10; // periodo = 833 350 us = 0.833 s = (CB746)
			buf[7] = 0x27; // 
			buf[8] = 0x00; // 
			buf[9] = 0x10; // images

		
usleep(1000);
			while (write(teste->kI2CFileDescriptor, buf, 13) < 1){
				usleep(1000);
				if (showErro) printf("Erro de escrita do PDVE.\n");
			}
*/


usleep(100000);
			buf[0] = 0xfd; // Data Validate
			buf[1] = 0x00; // Valida o PDVE
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de validacao.\n");
			}

			// read?
			int x;
			buf[0] = 0x7d;
			x = (int) read(teste->kI2CFileDescriptor, buf, 1);
			// printf("primeira leitura = %d\n", x);
			usleep (100000);

			/*x = (int) read(teste->kI2CFileDescriptor, buf, 1);
			char ch = read(teste->kI2CFileDescriptor, buf, 1);
			printf("segunda leitura = %d\n", x);
			cout << hex << (int) ch << endl;*/

			/*buf[1] = read(teste->kI2CFileDescriptor, buf, 1);
			x = atoi(buf[1]);
			printf("segunda leitura = %d\n", x);*/

						
usleep(100000);
			buf[0] = 0xe5; // PDVE status
			buf[1] = 0x02; // Start
while(operacao == "6") {	
printf( "iniciar?\n");
getline(cin, operacao);
}			

			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de inicio do padrao.\n");
			}


			while (operacao != "s") {
				printf( "Digite s para parar.\n");
				getline(cin, operacao);
			}
usleep(100000);
			buf[0] = 0xe5; // PDVE status
			buf[1] = 0x00; // Stop
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de parada do padrao.\n");
			}

usleep(100000);
			buf[0] = 0xe9; // Set Display 
			buf[1] = 0x00; // video mode
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Nao foi possivel setar o display como video.\n");
			}

		} else if (operacao == "7"){
			buf[0] = 0xe9; // Set Display 
			buf[1] = 0x01; // pattern mode
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Nao foi possivel setar o display como teste.\n");
			}

usleep(100000);
			buf[0] = 0xef; // Pattern Display
			buf[1] = 0x03; // From Flash
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Nao foi possivel escolher padrao da flash.\n");
			}
usleep(100000);
			buf[0] = 0xf0; // Trigger
			buf[1] = 0x03; // for Variable Exposure
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de aplicar trigger interno.\n");
			}
usleep(100000);
			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x03; // Open Mailbox for Variable Exposure
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de abertura do mailbox.\n");
			}

usleep(100000);
			buf[0] = 0xdb; // PDVE Control
			buf[1] = 0x01; // 1+1 exposure pattern
			buf[2] = 0x00; // 
			buf[3] = 0x01; // 1+1 patterns to display
			buf[4] = 0x00; // 
			buf[5] = 0x01; // 1+1 images
			buf[6] = 0x01; // always repeat 
 
		
			while (write(teste->kI2CFileDescriptor, buf, 7) < 1){
				usleep(100);
				if (showErro) printf("Erro de controle do PDVE.\n");
			}
usleep(100000);
			buf[0] = 0xdc; // LUT Offset
			buf[1] = 0x00; // inicio: 0
			buf[2] = 0x00;

			while (write(teste->kI2CFileDescriptor, buf, 3) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita da LUT de offset.\n");
			}
usleep(100000);
			buf[0] = 0xdd; // LUT Data
			buf[1] = 0x00; // trigger in + index
			buf[2] = 0x28; // bit-depth + LED blue on 4
			buf[3] = 0x00; // trigger out + no black-fill
			buf[4] = 0x00; // 
			buf[5] = 0x8d; // exposicao por imagem = 16 667 us = (0x411b)
			buf[6] = 0x20; // 
			buf[7] = 0x00; // 
			buf[8] = 0x00; //  
			buf[9] = 0x8d; // periodo = 833 350 us = 0.833 s = (CB746)
			buf[10] = 0x20; // 
			buf[11] = 0x00; // 
			buf[12] = 0x00; // images

		

			while (write(teste->kI2CFileDescriptor, buf, 13) < 1){
				usleep(1000);
				if (showErro) printf("Erro de escrita do PDVE.\n");
			}
usleep(100000);
			buf[0] = 0xdc; // LUT Offset
			buf[1] = 0x01; // +1
			buf[2] = 0x00;

			while (write(teste->kI2CFileDescriptor, buf, 3) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita da LUT de offet.\n");
			}
usleep(100000);
			buf[0] = 0xdd; // LUT Data
			buf[1] = 0x00; // trigger in + index 
			buf[2] = 0x18; // bit-depth + LED red on
			buf[3] = 0x00; // trigger out + no black-fill
			buf[4] = 0x00; // 
			buf[5] = 0x8d; // images
			buf[6] = 0x20; // always repeat
			buf[7] = 0x00; //  
			buf[8] = 0x00; // 
			buf[9] = 0x8d; // 
			buf[10] = 0x20; // 
			buf[11] = 0x00; // images
			buf[12] = 0x00; // 
			
usleep(100000);			
			while (write(teste->kI2CFileDescriptor, buf, 13) < 1){
				usleep(1000);
				if (showErro) printf("Erro de escrita do PDVE 2.\n");
			}

			
usleep(100000);
			
			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x00; // Close Mailbox
	
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de fechamento do mailbox.\n");

			}

			buf[0] = 0xdc; // LUT Offset
			buf[1] = 0x00; // Reset
			buf[2] = 0x00; 
usleep(100000);		
			while (write(teste->kI2CFileDescriptor, buf, 3) < 1){
				usleep(100);
				if (showErro) printf("Erro de reset da LUT de offet.\n");
			}

			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x01; // Image Index Mailbox
usleep(100000);		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de abertura do mailbox.\n");
			}

			buf[0] = 0xf6; // Offset Pointer
			buf[1] = 0x00; // inicializacao em 0
usleep(100000);		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de reset do pointer de offet.\n");
			}
usleep(100000);
			buf[0] = 0xf8; // Pattern Data
			buf[1] = 0x00; // image Index
			buf[2] = 0x00; // 
			// buf[3] = 0x02; //  
		
			while (write(teste->kI2CFileDescriptor, buf, 3) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita do dado de padrao.\n");
			}/*

usleep(100000);
			buf[0] = 0xf6; // Offset Pointer
			buf[1] = 0x01; // +1
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de reset do pointer de offet.\n");
			}
usleep(100000);
			buf[0] = 0xf8; // Pattern Data
			buf[1] = 0x0; // image Index
			// buf[2] = 0x01; // 
			// buf[3] = 0x02; // 
		


			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita do dado de padrao.\n");
			}*/

usleep(100000);
			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x00; // Close Mailbox
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de fechamento do mailbox.\n");
			}

			/*

			buf[1] = 0xe6; // 
			buf[2] = 0x10; // exposicao por imagem = 16 667 us = (0x411b)
			buf[3] = 0x27; // 
			buf[4] = 0x00; // 
			buf[5] = 0x10; //  
			buf[6] = 0x10; // periodo = 833 350 us = 0.833 s = (CB746)
			buf[7] = 0x27; // 
			buf[8] = 0x00; // 
			buf[9] = 0x10; // images

		
usleep(1000);
			while (write(teste->kI2CFileDescriptor, buf, 13) < 1){
				usleep(1000);
				if (showErro) printf("Erro de escrita do PDVE.\n");
			}
*/


usleep(100000);
			buf[0] = 0xfd; // Data Validate
			buf[1] = 0x00; // Valida o PDVE
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de validacao.\n");
			}

			// read?
			int x;
			buf[0] = 0x7d;
			x = (int) read(teste->kI2CFileDescriptor, buf, 1);
			// printf("primeira leitura = %d\n", x);
			usleep (100000);

			/*x = (int) read(teste->kI2CFileDescriptor, buf, 1);
			char ch = read(teste->kI2CFileDescriptor, buf, 1);
			printf("segunda leitura = %d\n", x);
			cout << hex << (int) ch << endl;*/

			/*buf[1] = read(teste->kI2CFileDescriptor, buf, 1);
			x = atoi(buf[1]);
			printf("segunda leitura = %d\n", x);*/

						
usleep(100000);
			buf[0] = 0xe5; // PDVE status
			buf[1] = 0x02; // Start
while(operacao == "7") {	
printf( "iniciar?\n");
getline(cin, operacao);
}			

			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de inicio do padrao.\n");
			}


			while (operacao != "s") {
				printf( "Digite s para parar.\n");
				getline(cin, operacao);
			}
usleep(100000);
			buf[0] = 0xe5; // PDVE status
			buf[1] = 0x00; // Stop
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de parada do padrao.\n");
			}

usleep(100000);
			buf[0] = 0xe9; // Set Display 
			buf[1] = 0x00; // video mode
		
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Nao foi possivel setar o display como video.\n");
			}

		} else if (operacao == "9"){
			buf[0] = 0xe9; // Set Display 
			buf[1] = 0x01; // pattern mode
			usleep(100);
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
			usleep(100);
			buf[0] = 0xf5; // Lut Control
			buf[1] = 0x01; // 1+1 patterns
			buf[2] = 0x01; // repeat
			buf[3] = 0x01; // 1+1 trigger out pulses
			buf[4] = 0x01; // 1+1 images
			wt = write(teste->kI2CFileDescriptor, buf, 5);
usleep(10000);
			while ( wt < 1){
				usleep(10000);
				if (showErro) printf("Erro ao configurar Control LUT.\n");
				wt = write(teste->kI2CFileDescriptor, buf, 5);
			}

			buf[0] = 0xf0; // Trigger Mode
			buf[1] = 0x01; // Mode 1
			usleep(100);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de abertura do mailbox.\n");
			}

			buf[0] = 0xe6; // Pattern times (exposure e frame)
			buf[1] = 0x8d; // exposicao por imagem 	= 16 667 us = (0x411b)
			buf[2] = 0x20; // 			=  8 333 us = (0x208d)
			buf[3] = 0x00; // 
			buf[4] = 0x00; //  
			buf[5] = 0x8d; // periodo = 833 350 us = 0.833 s = (CB746)
			buf[6] = 0x20; // 
			buf[7] = 0x00; // 
			buf[8] = 0x00; // images

			wt = write(teste->kI2CFileDescriptor, buf, 9);
usleep(10000);
			while (wt < 1){
				usleep(1000);
				if (showErro) printf("Erro de escrita do PDVE.\n");
				wt = write(teste->kI2CFileDescriptor, buf, 9);
			}
			
			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x01; // Image Mailbox
 	
			usleep(100);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de controle do PDVE.\n");
			}


			buf[0] = 0xf6; // LUT Offset Pointer
			buf[1] = 0x00; // inicio: 0
usleep(100);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita da LUT de offset.\n");
			}

			buf[0] = 0xf8; // LUT Data
			buf[1] = 0x01; // index 0
			buf[2] = 0x2; // index 1
				wt = write(teste->kI2CFileDescriptor, buf, 3);
		
usleep(1000);
			while (wt < 1){
				usleep(1000);
				if (showErro) printf("Erro de escrita do PDVE.\n");
				wt = write(teste->kI2CFileDescriptor, buf, 3);
			}


			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x00; // Close Mailbox
usleep(100);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita da LUT de offet.\n");
			}

			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x02; // Pattern Sequence Mailbox
 
		usleep(100);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de controle do PDVE.\n");
			}

			

			buf[0] = 0xf6; // LUT Offset Pointer
			buf[1] = 0x00; // inicio: 0
usleep(100);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita da LUT de offset.\n");
			}


			buf[0] = 0xf8; // LUT Data
			buf[1] = 0x00; // Pattern Number + trigger in
			buf[2] = 0x18; // RED led + 8-bit Depth
			buf[3] = 0x04; // Buffer Swap, no black-fill, no pattern inversion
				wt = write(teste->kI2CFileDescriptor, buf, 4);

usleep(100000);
			while (wt < 1){
				usleep(100);
				if (showErro) printf("Erro de fechamento do mailbox.\n");
				wt = write(teste->kI2CFileDescriptor, buf, 4);

			}

			buf[0] = 0xf6; // LUT Offset Pointer
			buf[1] = 0x01; // +1
usleep(100);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de escrita da LUT de offset.\n");
			}


			buf[0] = 0xf8; // LUT Data
			buf[1] = 0x00; // Pattern Number + trigger in
			buf[2] = 0x48; // RED led + 8-bit Depth
			buf[3] = 0x04; // Buffer Swap, no black-fill, no pattern inversion
				wt = write(teste->kI2CFileDescriptor, buf, 4);

usleep(100000);
			while (wt < 1){
				usleep(100);
				if (showErro) printf("Erro de fechamento do mailbox.\n");
				wt = write(teste->kI2CFileDescriptor, buf, 4);

			}

			buf[0] = 0xf7; // LUT Acess
			buf[1] = 0x00; // Close Mailbox
		usleep(100);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de reset do pointer de offet.\n");
			}



			buf[0] = 0xfd; // Data Validate
			buf[1] = 0x00; // Valida o PDVE
		usleep(100);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de validacao.\n");
			}

			// read?
			int x;
			buf[0] = 0x7d;
			x = (int) read(teste->kI2CFileDescriptor, buf, 1);
			printf("primeira leitura = %d\n", x);
			usleep (100000);

			/*x = (int) read(teste->kI2CFileDescriptor, buf, 1);
			char ch = read(teste->kI2CFileDescriptor, buf, 1);
			printf("segunda leitura = %d\n", x);
			cout << hex << (int) ch << endl;*/

			/*buf[1] = read(teste->kI2CFileDescriptor, buf, 1);
			x = atoi(buf[1]);
			printf("segunda leitura = %d\n", x);*/

						
usleep(100000);
			buf[0] = 0xe5; // PDVE status
			buf[1] = 0x02; // Start
while(operacao == "9") {	
printf( "iniciar?.\n");
getline(cin, operacao);
}			
usleep(100);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de inicio do padrao.\n");
			}

usleep(100);
			while (operacao != "s") {
				printf( "Digite s para parar.\n");
				getline(cin, operacao);
			}

			buf[0] = 0xe5; // PDVE status
			buf[1] = 0x00; // Stop
		usleep(100);
			while (write(teste->kI2CFileDescriptor, buf, 2) < 1){
				usleep(100);
				if (showErro) printf("Erro de parada do padrao.\n");
			}


			buf[0] = 0xe9; // Set Display 
			buf[1] = 0x00; // video mode
		usleep(100);
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

		} else if (operacao != "0"){
			cout << "Opcao invalida." << endl;
		}
	if (operacao == "0") cout << "Terminando o programa..." << endl;
	else cout << "Teste concluido, retornando ao menu inicial..." << endl << endl;
	}
	teste->closeDLP();
}

