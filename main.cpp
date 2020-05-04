#include "translator.h"

//!  Classe contenant le main()
/*!
  Execute le programme principal
*/
int main() {

    Translator* translator = new Translator("facturator.txt", "dacount.txt");

    translator->extract();
    translator->print();
    translator->write();

    delete translator;
}