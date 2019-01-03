
/**
 * @file
 * Tests
 */

class Test1Callback: public Timeout {
  protected:
    void callback() {
      Serial.write("$ ::callback\t\t\t\t[OK]");
      Serial.write(" - Это сообщение должно быть только 1 раз. \n");
    }
};

void test_1() {
  Serial.println("______________________Тест №1");
  Serial.println("# Проверка простого каллбека.");
  
  Serial.write("$ new Test1Timeout");
  
  Test1Callback * callback = new Test1Callback;
  
  Serial.write("\t\t\t[OK] \n");
  
  Serial.write("$ set_timeout(callback, 1000) ");

  int i = set_timeout(callback, 0);

  if (i >= 0) {
    Serial.write("[");
    Serial.print(i);  
    Serial.write("]\t\t[OK]\n");  
  }
  else {
    Serial.write("Index: ");  
    Serial.print(i);  
    Serial.write("\t\t\t\t[ERROR]\n");
    Serial.end();
    exit(1);
  }

//  clear_timeout(0);
}

class Test2Callback: public Timeout {
  public:
    int index;
  protected:
    void callback() {
       Serial.begin(9600);
      Serial.write("$ ::callback\t\t\t\t[OK]");
      Serial.write(" - Это сообщение должно быть только ");
      Serial.print(MAX_SIZE_OF_TIMEOUT_QUEUE);
      Serial.write(" раз. \n");
      Serial.println(this->index);
       Serial.end();
    }
};

void test_2() {
  Serial.println("______________________Тест №2");
  Serial.println("# Проверка Максимальной загрузки коллбека.");
  Serial.write("# Максимум: ");
  Serial.print(MAX_SIZE_OF_TIMEOUT_QUEUE);
  Serial.write(" -> ");
  
  int count = MAX_SIZE_OF_TIMEOUT_QUEUE;
  
  Test2Callback * callback[count];
  
  for (int i = 0; i < count; i++) {
    Serial.print(i);
    Serial.print("[");
    
    callback[i] = new Test2Callback;
    callback[i]->index = i;
    int index = set_timeout(
      callback[i],
      0
    );
    
    Serial.print(index);    
    Serial.print("]");
    if (index == NO_FREE_INDEX) {
      Serial.print("\n Свободных ячеек больше нет \n обрыв на ");
      Serial.print(i);
      Serial.print(" элементе.");
      Serial.end();
      exit(1);
    }
    Serial.print(",");
  }

  Serial.print("\n");
}

void run_test() {
  Serial.println("Запуск тестов:");
 
//  test_1();

  test_2();
  
  Serial.println("Конец.");
  Serial.end();
}
