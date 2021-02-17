#pragma once
#include "PuertoSerie.h"
#include <iostream>
#include <fstream>
#include <msclr\marshal.h>
#include "BinarY.h"
using namespace std;
namespace ESE_GRS_Send_COM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class ESE_GRS_Form : public System::Windows::Forms::Form
	{
		
	public:
		int wigth ;
		int f;
		int height;
		unsigned int animacion;
		PuertoSerie*puerto;
		bool txt,errtxt;
		unsigned int contLineas,contContLineas;
		bool inicarTransmiciones,Boolcont,firstEntry;
	private: System::Windows::Forms::ComboBox^  comboBoxSpeed;
	public: 

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ESE_GRS_Form()
		{
			if (components)
			{
				delete components;
			}
			if(puerto->EstaConectado())
						puerto->~PuertoSerie();
		}
	private: 
	 System::Windows::Forms::Label^  labelPuerto;
	 System::Windows::Forms::ComboBox^  comboBoxPuerto;
	 System::Windows::Forms::Button^  button1;
	 System::Windows::Forms::Label^  labelDatos;
	 System::Windows::Forms::TextBox^  textBoxDatos;
	 System::ComponentModel::IContainer^  components;
	 System::Windows::Forms::Label^  label1;
	 System::Windows::Forms::Timer^  enviaDatos;
	 System::Windows::Forms::RadioButton^  radioButtonUnaVez;
	 System::Windows::Forms::RadioButton^  radioButtonContinuo;
	 System::Windows::Forms::RadioButton^  radioButtonTXT;
	 System::Windows::Forms::RadioButton^  radioButtonBinary;
	 System::Windows::Forms::RadioButton^  radioButtonTXTBinary;


 
		

	 /////////////////////CONSTRUCTOR//////////////////////////////////////////

	public: 
		ESE_GRS_Form(void)
		{
			
			inicarTransmiciones=false;
			puerto=new PuertoSerie();
			txt=false;
			errtxt=false;
			f=0;
			animacion=0;
			contLineas=contContLineas=0;
			Boolcont=firstEntry=false;
			 
			///////////////////////
			InitializeComponent();
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->labelPuerto = (gcnew System::Windows::Forms::Label());
			this->comboBoxPuerto = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->labelDatos = (gcnew System::Windows::Forms::Label());
			this->textBoxDatos = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->enviaDatos = (gcnew System::Windows::Forms::Timer(this->components));
			this->radioButtonUnaVez = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonContinuo = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonTXT = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonBinary = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonTXTBinary = (gcnew System::Windows::Forms::RadioButton());
			this->comboBoxSpeed = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// labelPuerto
			// 
			this->labelPuerto->AutoSize = true;
			this->labelPuerto->Location = System::Drawing::Point(20, 21);
			this->labelPuerto->Name = L"labelPuerto";
			this->labelPuerto->Size = System::Drawing::Size(82, 13);
			this->labelPuerto->TabIndex = 1;
			this->labelPuerto->Text = L"Puerto a enviar:";
			// 
			// comboBoxPuerto
			// 
			this->comboBoxPuerto->FormattingEnabled = true;
			this->comboBoxPuerto->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"COM1", L"COM2"});
			this->comboBoxPuerto->Location = System::Drawing::Point(23, 37);
			this->comboBoxPuerto->Name = L"comboBoxPuerto";
			this->comboBoxPuerto->Size = System::Drawing::Size(70, 21);
			this->comboBoxPuerto->TabIndex = 3;
			this->comboBoxPuerto->Text = L"COM1";
			this->comboBoxPuerto->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ESE_GRS_Form::comboBoxPuerto_MouseClick);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Lime;
			this->button1->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->button1->Location = System::Drawing::Point(86, 262);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Enviar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ESE_GRS_Form::button1_Click);
			// 
			// labelDatos
			// 
			this->labelDatos->AutoSize = true;
			this->labelDatos->Location = System::Drawing::Point(75, 61);
			this->labelDatos->Name = L"labelDatos";
			this->labelDatos->Size = System::Drawing::Size(76, 13);
			this->labelDatos->TabIndex = 5;
			this->labelDatos->Text = L"Datos a enviar";
			// 
			// textBoxDatos
			// 
			this->textBoxDatos->Location = System::Drawing::Point(66, 77);
			this->textBoxDatos->Name = L"textBoxDatos";
			this->textBoxDatos->Size = System::Drawing::Size(100, 20);
			this->textBoxDatos->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(83, 222);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Cartel escondido de error\r\n";
			this->label1->Visible = false;
			// 
			// enviaDatos
			// 
			this->enviaDatos->Interval = 250;
			this->enviaDatos->Tick += gcnew System::EventHandler(this, &ESE_GRS_Form::enviaDatos_Tick);
			// 
			// radioButtonUnaVez
			// 
			this->radioButtonUnaVez->AutoSize = true;
			this->radioButtonUnaVez->Checked = true;
			this->radioButtonUnaVez->Location = System::Drawing::Point(23, 114);
			this->radioButtonUnaVez->Name = L"radioButtonUnaVez";
			this->radioButtonUnaVez->Size = System::Drawing::Size(65, 17);
			this->radioButtonUnaVez->TabIndex = 8;
			this->radioButtonUnaVez->TabStop = true;
			this->radioButtonUnaVez->Text = L"Una vez";
			this->radioButtonUnaVez->UseVisualStyleBackColor = true;
			this->radioButtonUnaVez->CheckedChanged += gcnew System::EventHandler(this, &ESE_GRS_Form::radioButtonUnaVez_CheckedChanged);
			// 
			// radioButtonContinuo
			// 
			this->radioButtonContinuo->AutoSize = true;
			this->radioButtonContinuo->Location = System::Drawing::Point(23, 150);
			this->radioButtonContinuo->Name = L"radioButtonContinuo";
			this->radioButtonContinuo->Size = System::Drawing::Size(67, 17);
			this->radioButtonContinuo->TabIndex = 9;
			this->radioButtonContinuo->Text = L"Continuo";
			this->radioButtonContinuo->UseVisualStyleBackColor = true;
			this->radioButtonContinuo->CheckedChanged += gcnew System::EventHandler(this, &ESE_GRS_Form::radioButtonContinuo_CheckedChanged);
			// 
			// radioButtonTXT
			// 
			this->radioButtonTXT->AutoSize = true;
			this->radioButtonTXT->Location = System::Drawing::Point(23, 187);
			this->radioButtonTXT->Name = L"radioButtonTXT";
			this->radioButtonTXT->Size = System::Drawing::Size(61, 17);
			this->radioButtonTXT->TabIndex = 10;
			this->radioButtonTXT->TabStop = true;
			this->radioButtonTXT->Text = L"By TXT";
			this->radioButtonTXT->UseVisualStyleBackColor = true;
			this->radioButtonTXT->CheckedChanged += gcnew System::EventHandler(this, &ESE_GRS_Form::radioButtonTXT_CheckedChanged);
			// 
			// radioButtonBinary
			// 
			this->radioButtonBinary->AutoSize = true;
			this->radioButtonBinary->Location = System::Drawing::Point(138, 114);
			this->radioButtonBinary->Name = L"radioButtonBinary";
			this->radioButtonBinary->Size = System::Drawing::Size(67, 17);
			this->radioButtonBinary->TabIndex = 11;
			this->radioButtonBinary->TabStop = true;
			this->radioButtonBinary->Text = L"ToBinary";
			this->radioButtonBinary->UseVisualStyleBackColor = true;
			this->radioButtonBinary->CheckedChanged += gcnew System::EventHandler(this, &ESE_GRS_Form::radioButtonBinary_CheckedChanged);
			// 
			// radioButtonTXTBinary
			// 
			this->radioButtonTXTBinary->AutoSize = true;
			this->radioButtonTXTBinary->Location = System::Drawing::Point(138, 150);
			this->radioButtonTXTBinary->Name = L"radioButtonTXTBinary";
			this->radioButtonTXTBinary->Size = System::Drawing::Size(89, 17);
			this->radioButtonTXTBinary->TabIndex = 12;
			this->radioButtonTXTBinary->TabStop = true;
			this->radioButtonTXTBinary->Text = L"TXT to binary";
			this->radioButtonTXTBinary->UseVisualStyleBackColor = true;
			this->radioButtonTXTBinary->CheckedChanged += gcnew System::EventHandler(this, &ESE_GRS_Form::radioButtonTXTBinary_CheckedChanged);
			// 
			// comboBoxSpeed
			// 
			this->comboBoxSpeed->FormattingEnabled = true;
			this->comboBoxSpeed->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"9600", L"115200"});
			this->comboBoxSpeed->Location = System::Drawing::Point(138, 37);
			this->comboBoxSpeed->Name = L"comboBoxSpeed";
			this->comboBoxSpeed->Size = System::Drawing::Size(70, 21);
			this->comboBoxSpeed->TabIndex = 13;
			this->comboBoxSpeed->Text = L"9600";
			// 
			// ESE_GRS_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(235, 297);
			this->Controls->Add(this->comboBoxSpeed);
			this->Controls->Add(this->radioButtonTXTBinary);
			this->Controls->Add(this->radioButtonBinary);
			this->Controls->Add(this->radioButtonTXT);
			this->Controls->Add(this->radioButtonContinuo);
			this->Controls->Add(this->radioButtonUnaVez);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxDatos);
			this->Controls->Add(this->labelDatos);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBoxPuerto);
			this->Controls->Add(this->labelPuerto);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(251, 336);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(251, 336);
			this->Name = L"ESE_GRS_Form";
			this->Text = L"ESE_GRS_Form";
			this->Click += gcnew System::EventHandler(this, &ESE_GRS_Form::onClick);
			this->Resize += gcnew System::EventHandler(this, &ESE_GRS_Form::ESE_GRS_Form_Resize);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

private: System::Void enviaDatos_Tick(System::Object^  sender, System::EventArgs^  e) {
				 if(inicarTransmiciones==true)
				    {
					 if(puerto->Error()==true) 
					    {
						 label1->Text=gcnew String(puerto->ErrorStr());
						 label1->Visible=true;
						 label1->Location=Drawing::Point(0,223);
						 label1->BackColor = Drawing::Color::Red;
						 inicarTransmiciones=false;
						 System::Windows::Forms::MessageBox::Show(gcnew String(puerto->ErrorStr()));
						 return;
					    } 
					 else if(String::IsNullOrEmpty(textBoxDatos->Text))
					    {
						
						 label1->Location=Drawing::Point(0,223);
						 label1->Text="ERROR:Debe Ingresar algun dato para enviar";
						 label1->BackColor = Drawing::Color::Red;
						 label1->Visible=true;
						 inicarTransmiciones=false;
						 System::Windows::Forms::MessageBox::Show("ERROR:Debe Ingresar algun dato para enviar");
					     return;
					   }
					   iniciarEnvio();
					 
				  }
				else
				   {
					
					button1->Text="Comenzar";
				    this->button1->BackColor = System::Drawing::Color::Lime;
					enviaDatos->Enabled=false;
				   }
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			
			 if(inicarTransmiciones==false)
				  {
					label1->Visible=false;
				    button1->Text="Detener";
					this->button1->BackColor = Drawing::Color::Red;
			        inicarTransmiciones=true;
					if(puerto->EstaConectado())
						puerto->~PuertoSerie();
					puerto=new PuertoSerie(comboBoxPuerto->Text,comboBoxSpeed->Text);		
					enviaDatos->Enabled=true;
				 }
				 else
				 {
					 inicarTransmiciones=false;
					 label1->Visible=false;
			     }
				
					
					  

				 
			 }
private: System::Void comboBoxPuerto_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			  inicarTransmiciones=false;
			  label1->Visible=false;
		 }
private: System::Void ESE_GRS_Form_Resize(System::Object^  sender, System::EventArgs^  e) {
			 this->ClientSize =Drawing::Size(355, 342);
		 }
private: System::Void radioButtonUnaVez_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			  inicarTransmiciones=false;
			  label1->Visible=false;
		 }
private: System::Void radioButtonContinuo_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			  inicarTransmiciones=false;
			  label1->Visible=false;
		 }
private: System::Void radioButtonTXT_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 inicarTransmiciones=false;
		 if(!txt)
			 {
				 labelDatos->Text="TXT Address";
				 txt=true;
		     }
		 else
		 {
			 labelDatos->Text="Datos a enviar";
			 txt=false;
		 }
	}
private: System::Void radioButtonBinary_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 inicarTransmiciones=false;
			 label1->Visible=false;
			 if(radioButtonBinary->Checked==true)
			  textBoxDatos->Text="0000000100000111";
			 else
				 textBoxDatos->Text="";
		   }
private: System::Void radioButtonTXTBinary_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 inicarTransmiciones=false;
		 if(!txt)
			 {
				 labelDatos->Text="TXT Address";
				 txt=true;
		     }
		 else
		 {
			 labelDatos->Text="Datos a enviar";
			 txt=false;
		 }
		 }
private: System::Void onClick(System::Object^  sender, System::EventArgs^  e) {
			 if(!inicarTransmiciones)label1->Visible=false;
		 }
public:char* SendbyTXT(String^str,bool binary)
			 {

				 msclr::interop::marshal_context context;
	             const char*st=context.marshal_as<const char*>(str);
				 fstream f;
				 char*a;
				 f.open(st,ios::in);
				 if(!f.is_open())
					 errtxt=true;
				 else if(binary=false)
				  {
					  a=new char[2048];
					  if(!Boolcont)
					    {
					     while (f.getline(a,2048))
					       {
						    contContLineas++;
					       }
					     Boolcont=true;
						  a="Fin_Lectura_cant_lineas";
					    }
					  else
					  {
						 firstEntry=true;
						 if(contLineas<contContLineas)
				             for(unsigned int i=0;i<contLineas+1;i++)
					            f.getline(a,2048);
				  
						 else
							 a="Fin_Archivo";
					         contLineas++;
					  }
				  }
				 else//////////////////////////////////////////////////////////
				 {
					 a=new char[8];
					 a[8]=0;
					 for(unsigned i=0;i<contLineas;i++)
					      f>>a;
					 if(!f.eof())
					  {
						 f>>a;
						 if(f.eof())
							 return "End";
						 if(strlen(a)>7)
						 {
							 f.close();
							 return "Error2";
						 }
					      contLineas++;
					      for(unsigned i=0;i<strlen(a);i++)
						     if(a[i]!='0'&&a[i]!='1')
							   return "Error1";
						  f.close();
						  return a;
					     
					 }
					 else
					 {
						 f.close();
						 if(contLineas==0)
							 return "NULL";
						 return "End";
					 }
					 		 
				 }
				 f.close();
				 return a;
		     };
public:char* SendBinaryByTxt(String^str){
	    fstream f;
        msclr::interop::marshal_context context;
	    const char*cc=context.marshal_as<const char*>(textBoxDatos->Text);
		f.open(cc,ios::in);
		if(f.is_open())
		{
			char*c=new char[17];
			if(!Boolcont)
			{
				
			    while(f.getline(c,17))
				{
					if(strlen(c)!=16&&strlen(c)!=2)
				    {
					label1->Text=gcnew String("Secuencia de entrada no valida");
		            label1->Location=Drawing::Point(65,223);
	                label1->Visible=true;
		            label1->BackColor=Color::Red;
		            errtxt=false;
		            inicarTransmiciones=false;
	                System::Windows::Forms::MessageBox::Show("Secuencia de entrada no valida");
		            return "Error";
				
				    }  
					contLineas++;
				}
				Boolcont=true;
				f.close();
				return "First";
			}
			else
			{
				if(contLineas==contContLineas)
					return "Fin";
				else
				{
				for(unsigned i=0;i<contContLineas+1;i++)
					f.getline(c,17);
				contContLineas++;
				return c;
				}
			
			}
		}
		else
		{
          label1->Text=gcnew String("Archivo no encontrado");
		  label1->Location=Drawing::Point(70,223);
	      label1->Visible=true;
		  label1->BackColor=Color::Red;
		  errtxt=false;
		  inicarTransmiciones=false;
	      System::Windows::Forms::MessageBox::Show("Archivo no encontrado");
		  return "Error";
		}
		
	   
	   
	   
	   
	   }
public:void iniciarEnvio(){
		   if(radioButtonUnaVez->Checked)//UNA VES
                        {
						 puerto->Trasmitir(textBoxDatos->Text);
						 label1->Text="Enviado";
						 label1->Location=Drawing::Point(100,223);
						 label1->Visible=true;
						 label1->BackColor = Drawing::Color::Lime;
						 inicarTransmiciones=false;
					    }
					 else if(radioButtonContinuo->Checked)//CONTINUO
					     {
						  puerto->Trasmitir(textBoxDatos->Text);
						  label1->Location=Drawing::Point(90,223);
						  animacion==0?label1->Text="Enviando":animacion==1?label1->Text="Enviando.":animacion==2?label1->Text="Enviando..":animacion==3?label1->Text="Enviando...":animacion==4?label1->Text="Enviando....":label1->Text="Enviando.....";
						  animacion==6?animacion=0:animacion++;
						  label1->Visible=true;
						  label1->BackColor = Drawing::Color::Yellow; 
		                  }
					 else if(radioButtonTXT->Checked)//TXT
					    {
							
							char*c=SendbyTXT(textBoxDatos->Text,0);
							if(errtxt)
							{
							    label1->Text=gcnew String("Archivo no encontrado");
								label1->Location=Drawing::Point(70,223);
								label1->Visible=true;
								label1->BackColor=Color::Red;
								errtxt=false;
								inicarTransmiciones=false;
								System::Windows::Forms::MessageBox::Show("Archivo no encontrado");
							}
							else if(contLineas>contContLineas)
								{
								   label1->Location=Drawing::Point(30,223);
								   label1->BackColor=Color::Lime;
								   label1->Text="TXT ENVIADO CORRECTAMENTE"; 
								   errtxt=false;
							       inicarTransmiciones=false;
								   contLineas=contContLineas=0;
								   Boolcont=firstEntry=false;
								}
							else if(firstEntry)			     {
								
							  puerto->Trasmitir(c);
							  label1->Location=Drawing::Point(85,223);
							  label1->BackColor=Color::Lime;
							  animacion==0?label1->Text="EnviandoTXT":animacion==1?label1->Text="EnviandoTXT.":animacion==2?label1->Text="EnviandoTXT..":animacion==3?label1->Text="EnviandoTXT...":animacion==4?label1->Text="EnviandoTXT....":label1->Text="EnviandoTXT.....";
						      animacion==6?animacion=0:animacion++;
							  label1->Visible=true;
						      label1->BackColor=Color::Lime;
							}
							
							
					    }
					 else if(radioButtonBinary->Checked)//BINARY
					 {
					
						 ToBinary(textBoxDatos,0);
                     }
					 else if(radioButtonTXTBinary->Checked)//TXT Binary
					 {
						 char*cc=SendBinaryByTxt(textBoxDatos->Text);
						 if(cc=="Fin")
						 {
						  label1->Location=Drawing::Point(30,223);
						  label1->BackColor=Color::Lime;
						  label1->Text="TXT ENVIADO CORRECTAMENTE"; 
						  inicarTransmiciones=false;
						  contLineas=contContLineas=0;
						  Boolcont=false;
						 }
						 else if(cc!="Error"&&cc!="First")
						 {
							  label1->Location=Drawing::Point(85,223);
							  label1->BackColor=Color::Lime;
							  animacion==0?label1->Text="EnviandoTXT":animacion==1?label1->Text="EnviandoTXT.":animacion==2?label1->Text="EnviandoTXT..":animacion==3?label1->Text="EnviandoTXT...":animacion==4?label1->Text="EnviandoTXT....":label1->Text="EnviandoTXT.....";
						      animacion==6?animacion=0:animacion++;
							  label1->Visible=true;
						      label1->BackColor=Color::Lime;
							 TextBox^t=gcnew TextBox();
							 t->Text=gcnew String(cc);
							 ToBinary(t,1);
						 }
						/*TextBox^t=gcnew TextBox();
						 
						 char*c=SendbyTXT(textBoxDatos->Text,1);
						 if(errtxt)
							{
							    label1->Text=gcnew String("Archivo no encontrado");
								label1->Location=Drawing::Point(70,223);
								label1->Visible=true;
								label1->BackColor=Color::Red;
								errtxt=false;
								inicarTransmiciones=false;
								System::Windows::Forms::MessageBox::Show("Archivo no encontrado");
							}
						 else if(c=="Error1"||c=="Error2")
						 {
						    label1->Location=Drawing::Point(0,223);
						    if(c=="Error1")
								label1->Text="Secuencia de entrada de datos incorrecta";
							else
								label1->Text="Secuencia de entrada de Bits mayor q 7";
							label1->BackColor = Drawing::Color::Red;
						    label1->Visible=true;
						    inicarTransmiciones=false;
							if(c=="Error1")
								 System::Windows::Forms::MessageBox::Show("Secuencia de entrada de datos incorrecta");
							else
								 System::Windows::Forms::MessageBox::Show("Secuencia de entrada de Bits mayor q 7");
						 
						 }
						 else if(c=="End")
						 {
						  label1->Location=Drawing::Point(30,223);
						  label1->BackColor=Color::Lime;
						  label1->Text="TXT ENVIADO CORRECTAMENTE"; 
						  errtxt=false;
						  inicarTransmiciones=false;
					      contLineas=0;
						  Boolcont=false;
						 }
						 else if(c=="NULL")
						 {
						 label1->Location=Drawing::Point(80,223);
						 label1->BackColor=Color::Yellow;
						 label1->Text="TXT Vacio"; 
						 label1->Visible=true;
						 errtxt=false;
						 inicarTransmiciones=false;
					     contLineas=0;
						 Boolcont=false;
						 System::Windows::Forms::MessageBox::Show("TXT Vacio");
						 
						 
						 }
						 else
						 {
						  char*f=new char[2];
						  f[0]=BinarY::ToCharacter(c,strlen(c));
						  f[1]=0;
						  if(strlen(f)==0)
						  puerto->Trasmitir("Null"); 
						  else
						  puerto->Trasmitir(f);
						     

						  label1->Location=Drawing::Point(85,223);
						  label1->BackColor=Color::Lime;
						  animacion==0?label1->Text="EnviandoTXT":animacion==1?label1->Text="EnviandoTXT.":animacion==2?label1->Text="EnviandoTXT..":animacion==3?label1->Text="EnviandoTXT...":animacion==4?label1->Text="EnviandoTXT....":label1->Text="EnviandoTXT.....";
						  animacion==6?animacion=0:animacion++;
					      label1->Visible=true;
						  label1->BackColor=Color::Lime;
						 
						 }
						 
					 
					 */}



	   }
public:void ToBinary(System::Windows::Forms::TextBox^s,bool text){
			  
			  
			  if(s->Text->Length%8!=0)
			                   {
								
			                     label1->Location=Drawing::Point(0,223);
		                         label1->Text="Secuencia de entrada de datos no leible";
                                 label1->BackColor = Drawing::Color::Red;			                  								
		                         label1->Visible=true;
		                         inicarTransmiciones=false;
			                     System::Windows::Forms::MessageBox::Show("error,solo se puede enviar 2 caracteres o un char[16] con los valores en binario de dichos caracteres");
			                     return;
			                   }

						  msclr::interop::marshal_context context;
						  const char*c=context.marshal_as<const char*>(s->Text);
						  bool error0=false;
						  for(int i=0;i<s->Text->Length;i++)
						    {
							if(i!=0&&i%8==0)
							{
								if(error0==false)
									break;
								error0=false;
							}
								if(c[i]=='1')
								error0=true;
							 if(c[i]!='0'&& c[i]!='1')
							   {
							    label1->Location=Drawing::Point(0,223);
						        label1->Text="Secuencia de entrada de bits incorrecta";
							    label1->BackColor = Drawing::Color::Red;
						        label1->Visible=true;
						        inicarTransmiciones=false;
						        System::Windows::Forms::MessageBox::Show("error,algunos de los caracteres no son ni 0 ni 1");
					            return;
							   }
						     }
						  if(!error0)
						  {
							    label1->Location=Drawing::Point(0,223);
						        label1->Text="Secuencia de entrada de bits incorrecta";
							    label1->BackColor = Drawing::Color::Red;
						        label1->Visible=true;
						        inicarTransmiciones=false;
						        System::Windows::Forms::MessageBox::Show("Error no puede enviar un binario con todos 0");
							    return;
						  }
						  unsigned strleN=(strlen(c)/8);
						  char*ch=new char[strleN+1];
						  ch[strleN]=0;
						  unsigned aument=0;
						  for(int i=strleN-1;i>=0;i--)
						  {
							  int decimd=0,multi=1;
							  char*d=new char[8];
							  for(unsigned ii=0;ii<8;ii++)
								  d[ii]=c[aument++];
							   for(int iii=7;iii>=0;iii--)
	                              {
		                            if(d[iii]=='1')
			                           decimd+=multi;
									multi*=2;
	                               }
							   ch[i]=decimd;
						  }
						   if(strlen(ch)!=0)
							   puerto->Trasmitir(ch);
						    if(!text)
								   {
									 label1->Text="Enviado";
						             label1->Location=Drawing::Point(100,223);
						             label1->Visible=true;
						             label1->BackColor = Drawing::Color::Lime;
						             inicarTransmiciones=false;
							    }
						
				          
						  /*int decimd=0,multi=1,decimf=0;
							  char*d=new char[8],*f=new char[8];
							  for(unsigned i=0;i<8;i++)
							  {
								  d[i]=c[i];
								  f[i]=c[i+8];
							  }
	                            for(int i=7;i>=0;i--)
	                              {
		                            if(d[i]=='1')
			                           decimd+=multi;
		                            if(f[i]=='1')
			                           decimf+=multi;
									multi*=2;
	                               }
							   char*caracter=new char[3];
							   caracter[0]=decimf;
							   caracter[1]=decimd;
							   caracter[2]=0;
							   if(strlen(caracter)!=0)
							   puerto->Trasmitir(caracter);
							   if(!text)
								   {
									 label1->Text="Enviado";
						             label1->Location=Drawing::Point(100,223);
						             label1->Visible=true;
						             label1->BackColor = Drawing::Color::Lime;
						             inicarTransmiciones=false;
							    }
						    }
			  
			  */
			  
			  
			  
			  
			  
			  
			  
			  
			  
			  
			  }



};
}

