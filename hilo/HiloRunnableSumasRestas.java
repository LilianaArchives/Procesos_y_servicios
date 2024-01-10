public class HiloRunnableSumasRestas implements Runnable{
    private int numero = 1000;
    private String operacion;
    private int numRepeticiones;

    @Override
    public void run() {
        //Si la operación es “+” se invocará al método incrementar
        //Si la operación es “-” se invocará al método decrementar
        if (operacion.equals("+")){
            System.out.println("Soy el hilo "+Thread.currentThread().getId()+" y este es el resultado final: "+incrementar(numRepeticiones));
        }else{
            System.out.println("Soy el hilo "+Thread.currentThread().getId()+" y este es el resultado final: "+decrementar(numRepeticiones));
        }
    }

    public HiloRunnableSumasRestas(int numRepeticiones, String operacion) {
        this.operacion = operacion;
        this.numRepeticiones = numRepeticiones;
    }
    public int incrementar(int numveces) {
        for (int i = 0; i < numveces; i++) {
            numero = 1 + numero;
        }
        return numero;
    }

    //Decrementará numero el numvece indicado
    public int decrementar(int numveces) {
        for (int i = 0; i < numveces; i++) {
            numero = numero - 1;
        }
        return numero;
    }
}
