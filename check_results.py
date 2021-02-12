import matplotlib.pyplot as plt
import os

LISTA = 'lista_uczniow.txt'

def get_pupils():
    return [e for e in open(LISTA).read().split('\n') if e != '']

def get_result_filenames():
    return [f'results/{e}.txt' for e in get_pupils()]


def get_with_calculated_total(data):
    for sort_name, d in data.items():
        for person, person_data in d.items():
            person_data['total'] = sum(person_data['ms'])

    return data


def get_whole_data():
    data = dict()
    for osoba, result_filename in zip(get_pupils(), get_result_filenames()):
        with open(result_filename) as file_obj:
            part_results = file_obj.read().split()
            sliced = [part_results[i:i+4] for i in range(0, len(part_results), 4)]
            for n, sort_name, verdict, ms in sliced:
                if sort_name not in data:
                    data[sort_name] = dict()
                if osoba not in data[sort_name]:
                    data[sort_name][osoba] = dict()


                for attr_name, val in zip(['ms', 'n', 'verdict'], [int(ms), int(n), verdict]):
                    if attr_name not in data[sort_name][osoba]:
                        data[sort_name][osoba][attr_name] = []
                    data[sort_name][osoba][attr_name].append(val)
    
    return get_with_calculated_total(data)


def gen_single_plot(plot_name, part_data, folder_name = 'images'):
    plt.clf()
    plt.title(plot_name)
    for person, person_data in part_data.items():
        verdict_table = ['OK' == e for e in person_data['verdict']]
        plt.plot(person_data['n'], person_data['ms'], label = '{}({}ms) {} / {}'.format(
            person, person_data['total'], sum(verdict_table), len(verdict_table)
        ))
    plt.xlabel('number of elements to sort')
    plt.ylabel('time in miliseconds')
    plt.legend()

    path = os.path.join(folder_name, plot_name) + '.png'
    try:
        os.makedirs(folder_name)
    except FileExistsError:
        print('[images created earlier..]')
    plt.savefig(path)


def gen_plots_from_data(data):
    for key, val in data.items():
        gen_single_plot(key, val)


if __name__ == '__main__':
    gen_plots_from_data(get_whole_data())

