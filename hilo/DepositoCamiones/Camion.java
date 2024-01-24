package DepositoCamiones;

/**
 * <h1>Clase Camion</h1>
 * <p>Esta clase extiende de la clase Thread. Las instancias de esta clase
 * llenarán su depósito</p>
 * <h2>Atributos</h2>
 * <ul>
 *     <li>numeroCamion: número de identificación del vehículo.</li>
 *     <li>deposito: Depósito de combustible. Llena el depósito del camión</li>
 * </ul>
 */
public class Camion extends Thread{
    /**
     * <p>Número de identificación del vehículo.</p>
     */
    private int numeroCamion;

    /**
     * <p>Depósito de combustible. Llena el depósito del camión</p>
     */
    private Deposito deposito;

    /**
     * <h2>Constructor Camion</h2>
     * <p>Ambos parámetros serán usados para instanciar los atributos de la clase.</p>
     * @param dep  variable de tipo Deposito (depósito de combustible).
     * @param n  variable de tipo int (número de vehículo).
     */
    public Camion (Deposito dep, int n)
    {
        deposito = dep;
        numeroCamion = n;
    }

    /**
     * <h2>Método <strong>run</strong></h2>
     * <p>
     * Este método se extiende de la clase Thread que define el comportamiento del hilo.
     * En este caso rellenamos cinco veces el depósito del camión enseñando cada vez cuánta cantidad se ha añadido y por
     * último muestra la cantidad de combustible total recogida en el depósito.
     * </p>
     */
    public void run()
    {
        double litrosEnDeposito = 0;
        for (int i = 0; i < 5; i++) {
            double litrosRepostados = deposito.repostarDepositoCamion();
            System.out.println("Camión"+numeroCamion+"carga: "+ litrosRepostados+" litros");
            litrosEnDeposito += litrosRepostados;
        }
        System.out.println("Camión "+ numeroCamion +" => Volumen Total Recogido = "+ litrosEnDeposito +" Operación carga finalizada!!");
    }

}
