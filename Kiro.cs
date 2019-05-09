ExpenseItHome.xaml.cs - клас:


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Collections.ObjectModel;

namespace ExpenseIt
{
    /// <summary>
    /// Interaction logic for ExpenseItHome.xaml
    /// </summary>
    public partial class ExpenseItHome : Page, INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;
        private DateTime lastChecked;
        public DateTime LastChecked
        {
            get { return lastChecked;}
            set { lastChecked = value; }
        }

        public ObservableCollection<string> PersonsChecked { get; set; }

        public ExpenseItHome()
        {
            InitializeComponent();
            LastChecked = DateTime.Now;
            this.DataContext = this;

            PersonsChecked = new ObservableCollection<string>();

        }



    /* private void Button_Click(object sender, RoutedEventArgs e)
     {
         string greetingMsg;
         greetingMsg = (peopleListBox.SelectedItem as ListBoxItem).ToString();
         MessageBox.Show("Hi " + greetingMsg);
     }
     */

    private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            // ExpenseReportPage expenseReportPage = new ExpenseReportPage();
            // this.NavigationService.Navigate(expenseReportPage);
            ExpenseReportPage expenseReportPage = new ExpenseReportPage(this.peopleListBox.SelectedItem);
            this.NavigationService.Navigate(expenseReportPage);
        }


        private void peopleListBox_SelectionChanged_1(object sender, SelectionChangedEventArgs e)
        {
            LastChecked = DateTime.Now;

            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs("LastChecked"));

            PersonsChecked.Add((peopleListBox.SelectedItem as System.Xml.XmlElement).Attributes["Name"].Value);

        }



    }


    //    ??????????????????
    internal interface INotifyPropertyChanged
    { 
    }
}

............................................................................................................................................................

ExpenseItHome.xaml - клас:


<Page x:Class="ExpenseIt.ExpenseItHome"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      xmlns:local="clr-namespace:ExpenseIt"
      mc:Ignorable="d" 
      d:DesignHeight="450" d:DesignWidth="800"
      Title="ExpenseIt-Home" Margin="10,0,10,10">

    <Grid>

        <Grid.Resources>
            <!-- Expense Report Data -->
            <XmlDataProvider x:Key="ExpenseDataSource" XPath="Expenses">
                <x:XData>
                    <Expenses xmlns="">
                        <Person Name="Mike" Department="Legal">
                            <Expense ExpenseType="Lunch" ExpenseAmount="50" />
                            <Expense ExpenseType="Transportation" ExpenseAmount="50" />
                        </Person>
                        <Person Name="Lisa" Department="Marketing">
                            <Expense ExpenseType="Document printing" ExpenseAmount="50"/>
                            <Expense ExpenseType="Gift" ExpenseAmount="125" />
                        </Person>
                        <Person Name="John" Department="Engineering">
                            <Expense ExpenseType="Magazine subscription" ExpenseAmount="50"/>
                            <Expense ExpenseType="New machine" ExpenseAmount="600" />
                            <Expense ExpenseType="Software" ExpenseAmount="500" />
                        </Person>
                        <Person Name="Mary" Department="Finance">
                            <Expense ExpenseType="Dinner" ExpenseAmount="100" />
                        </Person>
                        <Person Name="Theo" Department="Marketing">
                            <Expense ExpenseType="Dinner" ExpenseAmount="100" />
                        </Person>
                        <Person Name="James" Department="Machine Learning">
                            <Expense ExpenseType="New book" ExpenseAmount="16"/>
                            <Expense ExpenseType="Water" ExpenseAmount="33" />
                        </Person>
                        <Person Name="David" Department="Computer science">
                            <Expense ExpenseType="New course" ExpenseAmount="460"/>
                            <Expense ExpenseType="Cafe" ExpenseAmount="5" />
                        </Person>
                    </Expenses>
                </x:XData>
            </XmlDataProvider>
        </Grid.Resources>






        <Grid.ColumnDefinitions>
            <ColumnDefinition />
            <ColumnDefinition Width="230" />
        </Grid.ColumnDefinitions>
        <Grid.RowDefinitions>
            <RowDefinition Height="Auto" MinHeight="450"/>
            <RowDefinition />
            <RowDefinition Height="Auto"/>
            <RowDefinition />
        </Grid.RowDefinitions>


        <Label Grid.Column="1" Grid.Row="0"  VerticalAlignment="Center" Foreground="White" Background ="#4E87D4" Height="36" Margin="0,64,0,427" RenderTransformOrigin="0.5,0.5">Names
        </Label>

        <!-- People list -->
        <Label Grid.Column="1">View Expense Report</Label>
        <ListBox Name="peopleListBox" ItemsSource="{Binding Source={StaticResource ExpenseDataSource}, XPath=Person }" SelectionChanged="peopleListBox_SelectionChanged_1" Margin="0,100,0,235" Grid.Column="1" RenderTransformOrigin="0.5,0.5">
            <!--  <ListBox.RenderTransform>
                <TransformGroup>
                    <ScaleTransform/>
                    <SkewTransform AngleX="0.37"/>
                    <RotateTransform/>
                    <TranslateTransform X="0.494"/>
                </TransformGroup>
            </ListBox.RenderTransform>
            <Border Height="35" Padding="5" Background="#4E87D4">
                <Label VerticalAlignment="Center" 
                   Grid.Column="2" Grid.Row="1"
                   Foreground="White">Names</Label>
            </Border>
-->
            <ListBox.ItemTemplate>
                <DataTemplate>
                    <Label Content="{Binding XPath=@Name}"/>
                </DataTemplate>
            </ListBox.ItemTemplate>
        </ListBox>

        <Button Margin="116,314,0,189" Grid.Column="1" Click="Button_Click_1">
            <Grid>
                <Grid.RowDefinitions>
                    <RowDefinition/>
                    <RowDefinition/>
                </Grid.RowDefinitions>

                <Label Content="{Binding ElementName =peopleListBox,  Path=SelectedItem.Attributes[Name]}" Width="50" HorizontalAlignment="Right" Margin="-17,4,-33,6" Grid.RowSpan="2" RenderTransformOrigin="0.5,0.5">
                    <Label.RenderTransform>
                        <TransformGroup>
                            <ScaleTransform/>
                            <SkewTransform/>
                            <RotateTransform Angle="-1.18"/>
                            <TranslateTransform/>
                        </TransformGroup>
                    </Label.RenderTransform>
                </Label>
                <!--<Label Grid.Row="1" Content="ОК"/> -->
            </Grid>
        </Button>
        <Label Content="{Binding Path=LastChecked}" HorizontalAlignment="Left" Height="32" Margin="326,314,0,0" VerticalAlignment="Top" Width="188"/>

        <ListBox ItemsSource="{Binding Path=PersonsChecked}" Height="213" Margin="326,100,0,0" VerticalAlignment="Top"/>
        <Label Content="Last Previewed:" HorizontalAlignment="Left" Height="30" Margin="326,70,0,0" VerticalAlignment="Top" Width="160"/>

        <Grid.Background>
            <ImageBrush ImageSource="watermark.png"/>
        </Grid.Background>


    </Grid>
</Page>


.............................................................................................................................................................

ExpenseReportPage.xaml.cs - клас:


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ExpenseIt
{
    /// <summary>
    /// Interaction logic for ExpenseReportPage.xaml
    /// </summary>
    public partial class ExpenseReportPage : Page
    {
        public ExpenseReportPage()
        {
            InitializeComponent();
        }



        public ExpenseReportPage(object data) : this()
        {
            this.DataContext = data;
        }


    }
}


..............................................................................................................................................................

ExpenseReportPage.xaml - клас:


<Page x:Class="ExpenseIt.ExpenseReportPage"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      xmlns:local="clr-namespace:ExpenseIt"
      mc:Ignorable="d" 
      d:DesignHeight="450" d:DesignWidth="800"
      Title="ExpenseIt-View Expense">

    <Grid>
        <Grid>
            <Grid Grid.Column="1">

                <Grid Grid.Row="3" Margin="0,0,139,71">
                    <!--
                    <Grid.RowDefinitions>
                        <RowDefinition Height="Auto"/>
                        <RowDefinition Height="Auto"/>
                        <RowDefinition Height="Auto"/>
                        <RowDefinition Height="*"/>
                    </Grid.RowDefinitions>
                    <Grid.ColumnDefinitions>
                        <ColumnDefinition Width="*"/>
                        <ColumnDefinition Width="*"/>
                    </Grid.ColumnDefinitions>

                      
                    <Border Height="35" Padding="5" Background="#4E87D4">
                        <Label VerticalAlignment="Center" 
                   Grid.Column="0" Grid.Row="0"
                   Foreground="White">Expense Type</Label>
                    </Border>

                    <Label VerticalAlignment="Center" 
                   Grid.Column="1" Grid.Row="0"
                   Foreground="Blue">Amount</Label>

                     
                    <Label Grid.Column="0" Grid.Row="1">Semester Fee</Label>
                    <Label Grid.Column="0" Grid.Row="2">Elecricity</Label>
                    <Label Grid.Column="0" Grid.Row="3">Water</Label>
                    <Label Grid.Column="1" Grid.Row="1">350.00</Label>
                    <Label Grid.Column="1" Grid.Row="2">4.67</Label>
                    <Label Grid.Column="1" Grid.Row="3">33.95</Label>
-->
                    <DataGrid AutoGenerateColumns="False" RowHeaderWidth="0" ItemsSource="{Binding XPath=Expense}">
                        <DataGrid.Columns>
                            <DataGridTextColumn Header="ExpenseType" Binding="{Binding XPath=@ExpenseType}"/>
                            <DataGridTextColumn Header="Amount" Binding="{Binding XPath=@ExpenseAmount}"/>
                        </DataGrid.Columns>
                    </DataGrid>

                </Grid>

                <Grid.RowDefinitions>
                    <RowDefinition Height="*"/>
                    <RowDefinition Height="Auto"/>
                    <RowDefinition Height="Auto"/>
                    <RowDefinition Height="*"/>
                </Grid.RowDefinitions>


            </Grid>

            <Label Grid.Column="1" Grid.Row="0" Foreground="Blue" FontSize="36" FontFamily="Segoe UI Black">Expense Report For:</Label>
            <Label Content="Name:" Grid.Column="1" HorizontalAlignment="Left" Height="46" Margin="0,94,0,0" VerticalAlignment="Top" Width="126" FontSize="14" FontFamily="Segoe UI Black"/>
            <Label Content="Department:" Grid.Column="1" HorizontalAlignment="Left" Height="45" Margin="0,140,0,0" VerticalAlignment="Top" Width="142" FontSize="14" FontFamily="Segoe UI Black"/>

            <Label Content="{Binding XPath=@Name}" HorizontalAlignment="Left" Height="33" Margin="76,94,0,0" VerticalAlignment="Top" Width="266" Grid.Column="1"/>
            <Label Content="{Binding XPath=@Department}" HorizontalAlignment="Left" Height="32" Margin="118,140,0,0" VerticalAlignment="Top" Width="224" Grid.Column="1"/>


          <Grid.ColumnDefinitions>
                <ColumnDefinition Width="*"/>
                <ColumnDefinition Width="*"/>
            </Grid.ColumnDefinitions>

        </Grid>

        <Grid.Background>
            <ImageBrush ImageSource="watermark.png"/>
        </Grid.Background>
    </Grid>
</Page>
