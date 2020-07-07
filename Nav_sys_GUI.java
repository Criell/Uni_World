import java.awt.EventQueue;
import java.util.List;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTable;
import java.awt.Color;
import javax.swing.JScrollPane;
import javax.swing.table.DefaultTableModel;
import javax.swing.border.BevelBorder;
import javax.swing.SwingConstants;
import javax.swing.JTextPane;
import javax.swing.ImageIcon;
import javax.swing.JToggleButton;
import javax.swing.Icon;
import javax.swing.ScrollPaneConstants;

public class Nav_sys_GUI {

	private JFrame frame;
	private JTable table;
	private JTable table_1;
	private JTable table_2;
	public List<List<Integer>> Imap;
	public List<List<String>> arrMap;
	public Object arrTable[][];
	

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Nav_sys_GUI window = new Nav_sys_GUI();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Nav_sys_GUI() {
		initialize();
	}
	
	
	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		mapArray map = new mapArray();
		Imap = map.RetIArray();
		arrMap = map.arrString(Imap);
		
		frame = new JFrame();
		frame.getContentPane().setBackground(Color.DARK_GRAY);
		frame.setBounds(100, 100, 740, 570);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
		tabbedPane.setBackground(Color.DARK_GRAY);
		tabbedPane.setForeground(Color.DARK_GRAY);
		tabbedPane.setFont(new Font("Century Gothic", Font.BOLD, 16));
		tabbedPane.setBorder(null);
		tabbedPane.setBounds(0, 62, 728, 475);
		frame.getContentPane().add(tabbedPane);
		
		JPanel panel = new JPanel();
		panel.setForeground(Color.DARK_GRAY);
		panel.setBorder(null);
		panel.setBackground(Color.DARK_GRAY);
		tabbedPane.addTab("Main", (Icon) null, panel, null);
		tabbedPane.setForegroundAt(0, Color.GRAY);
		tabbedPane.setBackgroundAt(0, Color.DARK_GRAY);
		panel.setLayout(null);
		
		JLabel lblCo = new JLabel("OBSTACLE");
		lblCo.setForeground(Color.WHITE);
		lblCo.setHorizontalAlignment(SwingConstants.CENTER);
		lblCo.setFont(new Font("Century Gothic", Font.BOLD, 18));
		lblCo.setBounds(20, 17, 120, 23);
		panel.add(lblCo);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		scrollPane.setBounds(20, 46, 120, 365);
		panel.add(scrollPane);
		scrollPane.getViewport().setBorder(null);
		scrollPane.getViewport().setBackground(Color.DARK_GRAY);
		scrollPane.getViewport().setForeground(Color.DARK_GRAY);
		
		table = new JTable();
		table.setFont(new Font("Century Gothic", Font.PLAIN, 12));
		Object[][] obstacle = map.FindObs(arrMap);
		String headerO [] = { "X", "Y"};
		table.setModel(new DefaultTableModel(obstacle, headerO));
		
		table.getColumnModel().getColumn(0).setPreferredWidth(45);
		table.getColumnModel().getColumn(1).setPreferredWidth(45);
		scrollPane.setViewportView(table);
		
		JLabel lblSurvivor = new JLabel("SURVIVOR");
		lblSurvivor.setForeground(Color.WHITE);
		lblSurvivor.setHorizontalAlignment(SwingConstants.CENTER);
		lblSurvivor.setFont(new Font("Century Gothic", Font.BOLD, 18));
		lblSurvivor.setBounds(581, 17, 120, 23);
		panel.add(lblSurvivor);
		
		JScrollPane scrollPane_1 = new JScrollPane();
		scrollPane_1.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		scrollPane_1.setBounds(581, 46, 120, 182);
		panel.add(scrollPane_1);
		scrollPane_1.getViewport().setBorder(null);
		scrollPane_1.getViewport().setBackground(Color.DARK_GRAY);
		scrollPane_1.getViewport().setForeground(Color.DARK_GRAY);
		
		table_1 = new JTable();
		table_1.setFont(new Font("Century Gothic", Font.PLAIN, 12));
		Object[][] survivor = map.FindSuv(arrMap);
		String headerS [] = { "X", "Y"};
		table_1.setModel(new DefaultTableModel(survivor, headerS));
		
		table_1.getColumnModel().getColumn(0).setPreferredWidth(45);
		table_1.getColumnModel().getColumn(1).setPreferredWidth(45);
		scrollPane_1.setViewportView(table_1);
		
		JScrollPane scrollPane_2 = new JScrollPane();
		scrollPane_2.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		scrollPane_2.setBounds(158, 46, 406, 365);
		panel.add(scrollPane_2);
		scrollPane_2.getViewport().setBorder(null);
		scrollPane_2.getViewport().setBackground(Color.DARK_GRAY);
		scrollPane_2.getViewport().setForeground(Color.DARK_GRAY);
		
/*		JTabbedPane tabbedPane_1 = new JTabbedPane(JTabbedPane.TOP);
		scrollPane_2.setViewportView(tabbedPane_1);
*/		
		JLabel lblSos = new JLabel("SOS BOARD");
		lblSos.setForeground(Color.WHITE);
		lblSos.setHorizontalAlignment(SwingConstants.CENTER);
		lblSos.setFont(new Font("Century Gothic", Font.BOLD, 18));
		lblSos.setBounds(581, 239, 120, 28);
		panel.add(lblSos);
		
		JPanel panel_1 = new JPanel();
		panel_1.setBackground(Color.DARK_GRAY);
		tabbedPane.addTab("Report 1", (Icon) null, panel_1, null);
		tabbedPane.setForegroundAt(1, Color.GRAY);
		
		JPanel panel_2 = new JPanel();
		panel_2.setForeground(Color.WHITE);
		panel_2.setBackground(Color.DARK_GRAY);
		tabbedPane.addTab("Report 2", (Icon) null, panel_2, null);
		tabbedPane.setForegroundAt(2, Color.GRAY);
		tabbedPane.setBackgroundAt(2, Color.DARK_GRAY);
		
		table_2 = new JTable();
		table_2.setLocation(0, 46);
		table_2.setFont(new Font("Century Gothic", Font.PLAIN, 12));
		table_2.setBorder(new BevelBorder(BevelBorder.RAISED, Color.LIGHT_GRAY, null, null, null));
		Object[][] arrTable = map.ArrTableString(arrMap);
		String header [] = map.ArrHeader(arrMap);
		table_2.setModel(new DefaultTableModel( arrTable, header));		
		for (int n = 0; n < arrMap.size(); n++) {
				table_2.getColumnModel().getColumn(n).setPreferredWidth(arrMap.get(n).size());
		}

		scrollPane_2.setViewportView(table_2);		
		
		
		JLabel lblNavSys = new JLabel("");
		lblNavSys.setIcon(new ImageIcon("C:\\Users\\lina.maria.guevara\\eclipse-workspace\\Nav_Sys\\src\\botones diana-03.png"));
		lblNavSys.setFont(new Font("Arial", Font.BOLD, 16));
		lblNavSys.setBounds(10, 11, 166, 48);
		frame.getContentPane().add(lblNavSys);
				
		
		String SOSM = map.SOS(arrMap);
		
		JLabel lblMapMatrix = new JLabel("MAP MATRIX");
		lblMapMatrix.setHorizontalAlignment(SwingConstants.CENTER);
		lblMapMatrix.setForeground(Color.WHITE);
		lblMapMatrix.setFont(new Font("Century Gothic", Font.BOLD, 18));
		lblMapMatrix.setBounds(298, 17, 120, 23);
		panel.add(lblMapMatrix);
		
		JScrollPane scrollPane_3 = new JScrollPane();
		scrollPane_3.setBounds(581, 273, 120, 138);
		panel.add(scrollPane_3);
		
		JTextPane textPane = new JTextPane();
		scrollPane_3.setViewportView(textPane);
		textPane.setFont(new Font("Century Gothic", Font.PLAIN, 12));
		textPane.setText(SOSM);
		
		JToggleButton tglbtnNewToggleButton = new JToggleButton("");
		tglbtnNewToggleButton.setBackground(Color.DARK_GRAY);
		tglbtnNewToggleButton.setIcon(new ImageIcon("C:\\Users\\lina.maria.guevara\\eclipse-workspace\\Nav_Sys\\src\\botones diana-01.png"));
		tglbtnNewToggleButton.setSelectedIcon(new ImageIcon("C:\\Users\\lina.maria.guevara\\eclipse-workspace\\Nav_Sys\\src\\botones diana-02.png"));
		tglbtnNewToggleButton.setBounds(640, 11, 60, 60);
		tglbtnNewToggleButton.setBorder(null);
		frame.getContentPane().add(tglbtnNewToggleButton);
		tglbtnNewToggleButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				textPane.setText("");
			}
		});
	}
}