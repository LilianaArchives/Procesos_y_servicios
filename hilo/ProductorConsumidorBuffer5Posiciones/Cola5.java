package ProductorConsumidorBuffer5Posiciones;

public class Cola5 {
    private final int[] numeros = new int[5];
    private int disponibles = 5;
    private int numDevolver;
    private boolean disponible = false;
    private boolean todoLleno = false;

    public synchronized int get() {
        // Queda a la espera hasta que la cola se llene ("mientras cola vacía espero en wait()")
        while (!disponible) {
            try {
                wait();
            } catch (InterruptedException e) { }
        }
        //Una vez hay valor disponible se devuelve
        int proximodisponible = disponibles + 1;
        for (int i = 0; i < numeros.length; i++) {
            if ((numeros[i] != 0) && (disponibles + 1 == proximodisponible)){
                numDevolver = numeros[i];
                numeros[i] = 0;
                System.out.println("******Consumido número en buffer "+i+"******");
                disponibles ++;
                break;
            }
        }
        if (disponibles == 5){
            todoLleno = false;
            disponible = false;
        }
        notifyAll();
        return numDevolver;
    }


    public synchronized void put(int valor) {
        // Queda a la espera hasta que la cola se vacíe ("mientras haya datos en la cola espero en wait()")
        while (todoLleno){
            try {
                wait();
            } catch (InterruptedException e) { }
        }

        for (int i = 0; i < numeros.length; i++) {
            if (numeros[i] == 0){
                numeros[i] = valor;
                System.out.println("******Producido número en buffer "+i+"******");
                break;
            }
        }
        disponibles --;
        if (disponibles == 0)
            todoLleno = true;
        disponible = true;
        notifyAll();
    }
}
